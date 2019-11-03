//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_HETEROGENOUS_ACCESS_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HETEROGENOUS_ACCESS_NORMAL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/integral_size.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/detail/left_shift.hpp>
#include <mizuiro/color/detail/heterogenous/bits.hpp>
#include <mizuiro/color/detail/heterogenous/channel_bits.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/detail/promote_type.hpp>
#include <mizuiro/detail/range_to.hpp>
#include <mizuiro/detail/sum.hpp>
#include <mizuiro/detail/uint_least.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal/list/find.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace heterogenous
{

template<
	typename Format,
	typename Channel
>
class access_normal
{
private:
	typedef
	mizuiro::color::types::channel_value<
		Format,
		Channel
	>
	value_type;

	typedef
	mizuiro::integral_size<
		mizuiro::detail::sum<
			mizuiro::detail::range_to<
				typename
				Format::channel_bits,
				metal::find<
					typename
					Format::layout::channels,
					Channel
				>::value
			>
		>::value
	>
	start_bit;

	typedef
	mizuiro::color::detail::heterogenous::channel_bits<
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
	mizuiro::color::detail::heterogenous::bits<
		typename
		Format::channel_bits
	>
	total_bits;

	typedef
	mizuiro::integral_size<
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
	typename
	std::make_unsigned<
		mizuiro::detail::promote_type<
			color_uint
		>
	>::type
	promoted_color;

	template<
		mizuiro::size_type Begin,
		mizuiro::size_type Count
	>
	static
	constexpr
	color_uint
	bit_mask()
	{
		return
			static_cast<
				color_uint
			>(
				mizuiro::color::detail::left_shift<
					promoted_color,
					Begin
				>()
				^
				mizuiro::color::detail::left_shift<
					promoted_color,
					Begin
					+
					Count
				>()
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
					access_normal::bit_mask<
						real_start_bit::value,
						bit_count::value
					>()
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
				~access_normal::bit_mask<
					real_start_bit::value,
					bit_count::value
				>()
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
}

#endif
