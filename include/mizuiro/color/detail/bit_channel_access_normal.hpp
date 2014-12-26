//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_BIT_CHANNEL_ACCESS_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_BIT_CHANNEL_ACCESS_NORMAL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/detail/heterogenous_bits.hpp>
#include <mizuiro/color/detail/heterogenous_channel_bits.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/detail/uint_least.hpp>
#include <mizuiro/detail/promote_type.hpp>
#include <mizuiro/mpl/index_of.hpp>
#include <mizuiro/mpl/integral_size.hpp>
#include <mizuiro/mpl/range_to.hpp>
#include <mizuiro/mpl/sum.hpp>


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
	typedef
	mizuiro::color::types::channel_value<
		Format,
		Channel
	>
	value_type;

	typedef
	mizuiro::mpl::integral_size<
		mizuiro::mpl::sum<
			mizuiro::mpl::range_to<
				typename
				Format::channel_bits,
				mizuiro::mpl::index_of<
					typename
					Format::layout::order,
					Channel
				>()
			>
		>()
	>
	start_bit;

	typedef
	mizuiro::color::detail::heterogenous_channel_bits<
		Format,
		Channel
	>
	bit_count;

	typedef
	mizuiro::color::types::pointer<
		mizuiro::access::normal,
		Format,
		mizuiro::const_tag
	>
	const_pointer;

	typedef
	mizuiro::color::types::pointer<
		mizuiro::access::normal,
		Format,
		mizuiro::nonconst_tag
	>
	pointer;

	typedef
	mizuiro::color::detail::heterogenous_bits<
		typename
		Format::channel_bits
	>
	total_bits;

	typedef
	mizuiro::mpl::integral_size<
		total_bits::value
		-
		bit_count::value
		-
		start_bit::value
	>
	real_start_bit;

	typedef
	mizuiro::detail::uint_least<
		total_bits
	>
	color_uint;

	typedef
	mizuiro::detail::promote_type<
		color_uint
	>
	promoted_color;

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
