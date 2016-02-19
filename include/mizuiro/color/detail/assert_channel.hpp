//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_ASSERT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_ASSERT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/channel/is.hpp>


#define MIZUIRO_COLOR_DETAIL_ASSERT_CHANNEL(\
	name\
)\
static_assert(\
	mizuiro::color::channel::is<\
		name\
	>::value,\
	"Channel must be a channel type"\
)

#endif
