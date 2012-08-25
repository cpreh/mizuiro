//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_BIT_CHANNEL_ACCESS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_BIT_CHANNEL_ACCESS_HPP_INCLUDED

#include <mizuiro/const_raw_pointer.hpp>
#include <mizuiro/integral_size.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/raw_value.hpp>
#include <mizuiro/color/detail/heterogenous_channel_bits.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/bit_count.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <algorithm>
#include <boost/mpl/accumulate.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/divides.hpp>
#include <boost/mpl/iterator_range.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Format,
	typename Channel
>
class bit_channel_access
{
private:
	typedef typename mizuiro::color::types::channel_value<
		Format,
		Channel
	>::type value_type;

	typedef typename boost::mpl::accumulate<
		boost::mpl::iterator_range<
			typename boost::mpl::begin<
				typename Format::channel_bits
			>::type,
			typename boost::mpl::advance<
				typename boost::mpl::begin<
					typename Format::channel_bits
				>::type,
				typename mizuiro::detail::index_of<
					typename Format::layout::order,
					Channel
				>::type
			>::type
		>,
		typename mizuiro::integral_size<
			0u
		>::type,
		boost::mpl::plus<
			boost::mpl::_1,
			boost::mpl::_2
		>
	>::type start_bit;

	typedef typename mizuiro::color::detail::heterogenous_channel_bits<
		Format,
		Channel
	>::type bit_count;

	typedef typename mizuiro::detail::bit_count<
		mizuiro::raw_value
	>::type bits_per_byte;

	typedef typename boost::mpl::divides<
		start_bit,
		bits_per_byte
	>::type first_byte;

	static
	mizuiro::raw_value
	part(
		mizuiro::size_type const _begin,
		mizuiro::size_type const _count
	)
	{
		return
			static_cast<
				mizuiro::raw_value
			>(
				((1u << _begin) - 1u) ^ ((1u << (_begin + _count)) - 1u)
			);
	}

	static
	void
	set_bits(
		mizuiro::size_type const _begin,
		mizuiro::size_type const _count,
		mizuiro::raw_value const _value,
		mizuiro::raw_value &_result
	)
	{
		_result =
			static_cast<
				mizuiro::raw_value
			>(
				(
					_result
					&
					~bit_channel_access::part(
						_begin,
						_count
					)
				)
				|
				(
					_value
					<<
					_begin
				)
			);
	}

	static
	mizuiro::raw_value
	get_bits(
		mizuiro::size_type const _begin,
		mizuiro::size_type const _count,
		mizuiro::raw_value const _value
	)
	{
		return
			_value
			&
			bit_channel_access::part(
				_begin,
				_count
			);
	}

	template<
		typename Operation
	>
	static
	inline
	void
	loop_bits(
		mizuiro::const_raw_pointer _source,
		mizuiro::raw_pointer _dest,
		Operation const &_operation
	)
	{
		mizuiro::size_type current_bit(
			start_bit::value - bits_per_byte::value * first_byte::value
		);

		for(
			mizuiro::size_type remaining_bits(
				bit_count::value
			);
			bit_count::value >= remaining_bits && remaining_bits != 0;
			remaining_bits -= bits_per_byte::value, ++_dest, ++_source
		)
		{
			_operation(
				*_dest,
				*_source,
				current_bit,
				// The number of bits to set for the last byte
				// is remaining_bits. For the first bit, the
				// number is how many bits fit into the current
				// byte when current_bit is subtracted. If a
				// full byte is written, the second case also
				// takes care of that because current_bit will
				// be 0.
				std::min(
					remaining_bits,
					bits_per_byte::value - current_bit % bits_per_byte::value
				)
			);

			current_bit = 0u;
		}
	}

	static
	void
	read_bits(
		mizuiro::raw_value &_dest,
		mizuiro::raw_value const _source,
		mizuiro::size_type const _start_bit,
		mizuiro::size_type const _bit_count
	)
	{
		_dest =
			bit_channel_access::get_bits(
				_start_bit,
				_bit_count,
				_source
			);
	}

	static
	void
	write_bits(
		mizuiro::raw_value &_dest,
		mizuiro::raw_value const _source,
		mizuiro::size_type const _start_bit,
		mizuiro::size_type const _bit_count
	)
	{
		bit_channel_access::set_bits(
			_start_bit,
			_bit_count,
			_source,
			_dest
		);
	}
public:
	static
	value_type
	read(
		mizuiro::const_raw_pointer const _data
	)
	{
		value_type result(
			0u
		);

		bit_channel_access::loop_bits(
			_data
			+
			first_byte::value,
			reinterpret_cast<
				mizuiro::raw_pointer
			>(
				&result
			),
			&bit_channel_access::read_bits
		);

		return result;
	}

	static
	void
	write(
		mizuiro::raw_pointer const _data,
		value_type const _value
	)
	{
		bit_channel_access::loop_bits(
			reinterpret_cast<
				mizuiro::const_raw_pointer
			>(
				&_value
			),
			_data
			+
			first_byte::value,
			&bit_channel_access::write_bits
		);
	}
};

}
}
}

#endif
