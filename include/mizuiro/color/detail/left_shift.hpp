//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_LEFT_SHIFT_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_LEFT_SHIFT_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Type,
	mizuiro::size_type Count
>
inline
constexpr
typename
std::enable_if<
	Count
	==
	static_cast<
		mizuiro::size_type
	>(
		std::numeric_limits<
			Type
		>::digits
	),
	Type
>::type
left_shift()
{
	return
		~Type{
			0
		};
}

template<
	typename Type,
	mizuiro::size_type Count
>
inline
constexpr
typename
std::enable_if<
	Count
	<
	static_cast<
		mizuiro::size_type
	>(
		std::numeric_limits<
			Type
		>::digits
	),
	Type
>::type
left_shift()
{
	return
		(
			Type{
				1u
			}
			<<
			Count
		)
		-
		Type{
			1u
		};
}

}
}
}

#endif
