//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MIN_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MIN_HPP_INCLUDED

#include <mizuiro/color/access/channel_min.hpp>


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
		mizuiro::color::access::channel_min(
			_color.format_store(),
			_channel
		)
	);
}

}
}
}
}

#endif
