//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_BIT_CHANNEL_ACCESS_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_BIT_CHANNEL_ACCESS_NORMAL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/integral_size.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/detail/heterogenous_bits.hpp>
#include <mizuiro/color/detail/heterogenous_channel_bits.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/detail/uint_least.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/accumulate.hpp>
#include <boost/mpl/advance.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/iterator_range.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/type_traits/promote.hpp>
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
class bit_channel_access_normal
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

	typedef typename mizuiro::color::types::pointer<
		mizuiro::access::normal,
		Format,
		mizuiro::const_tag
	>::type const_pointer;

	typedef typename mizuiro::color::types::pointer<
		mizuiro::access::normal,
		Format,
		mizuiro::nonconst_tag
	>::type pointer;

	typedef typename mizuiro::color::detail::heterogenous_bits<
		typename Format::channel_bits
	>::type total_bits;

	typedef mizuiro::integral_size<
		total_bits::value - bit_count::value - start_bit::value
	> real_start_bit;

	typedef typename mizuiro::detail::uint_least<
		total_bits
	>::type color_uint;

	typedef typename boost::promote<
		color_uint
	>::type promoted_color;

	static
	color_uint
	part(
		mizuiro::size_type const _begin,
		mizuiro::size_type const _count
	)
	{
		promoted_color const one(
			1u
		);

		return
			static_cast<
				color_uint
			>(
				((one << _begin) - one) ^ ((one << (_begin + _count)) - one)
			);
	}
public:
	static
	value_type
	read(
		const_pointer const _data
	)
	{
		return
			static_cast<
				value_type
			>(
				(
					bit_channel_access_normal::part(
						real_start_bit::value,
						bit_count::value
					)
					&
					*_data
				)
				>>
				real_start_bit::value
			)
			;
	}

	static
	void
	write(
		pointer const _data,
		value_type const _value
	)
	{
		*_data
			=
			static_cast<
				color_uint
			>(
				*_data
				&
				~bit_channel_access_normal::part(
					real_start_bit::value,
					bit_count::value
				)
			);

		*_data
			=
			static_cast<
				color_uint
			>(
				*_data
				|
				static_cast<
					color_uint
				>
				(
					_value
				)
				<<
				real_start_bit::value
			)
			;
	}
};

}
}
}

#endif
