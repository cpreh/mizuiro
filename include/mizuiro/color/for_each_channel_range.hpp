//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FOR_EACH_CHANNEL_RANGE_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_EACH_CHANNEL_RANGE_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/make_range.hpp>
#include <mizuiro/range/for_each_range.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Function
>
inline
void
for_each_channel_range(
	Color const &_color,
	Function const &_function
)
{
	static_assert(
		mizuiro::color::is_color<
			Color
		>::value,
		"Color must be a color type"
	);

	mizuiro::range::for_each_range(
		mizuiro::color::make_range(
			_color
		),
		_function
	);
}

}
}

#endif
