//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_MAKE_RANGE_HPP_INCLUDED
#define MIZUIRO_COLOR_MAKE_RANGE_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/access/channels.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::color
{

template<
	typename Color
>
inline
decltype(
	mizuiro::color::access::channels<
		typename
		Color::format
	>(
		std::declval<
			Color
		>().format_store()
	)
)
make_range(
	Color const &_color
)
{
	static_assert(
		mizuiro::color::is_color<
			Color
		>::value,
		"Color must be a color type"
	);

	return
		mizuiro::color::access::channels<
			typename
			Color::format
		>(
			_color.format_store()
		);
}

}

#endif
