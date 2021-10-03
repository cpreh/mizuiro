//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SET_PERCENTAGE_HPP_INCLUDED
#define MIZUIRO_COLOR_SET_PERCENTAGE_HPP_INCLUDED

#include <mizuiro/color/denormalize.hpp>


namespace mizuiro::color
{

template<
	typename Color,
	typename Channel,
	typename Float
>
void
set_percentage(
	Color &_color,
	Channel const &_channel,
	Float const _value
)
{
	_color.set(
		_channel,
		mizuiro::color::denormalize<
			typename
			Color::format
		>(
			_color.format_store(),
			_channel,
			_value
		)
	);
}

}

#endif
