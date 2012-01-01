//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MIN_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MIN_HPP_INCLUDED

#include <mizuiro/color/channel_min.hpp>
#include <mizuiro/color/types/channel_value.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Channel,
	typename Color
>
void
channel_to_min(
	Color &_color,
	Channel const &_channel
)
{
	_color.set(
		_channel,
		color::channel_min<
			typename color::types::channel_value<
				typename Color::format,
				Channel
			>::type
		>()
	);
}

}
}
}
}

#endif
