//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DETAIL_ASSERT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DETAIL_ASSERT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/channel/is.hpp>
#include <mizuiro/color/types/valid_channel_type.hpp>


#define MIZUIRO_COLOR_FORMAT_DETAIL_ASSERT_CHANNEL(\
	format,\
	name\
) \
static_assert( \
	mizuiro::color::channel::is<\
		name\
	>::value \
	|| \
	mizuiro::color::types::valid_channel_type<\
		format,\
		name\
	>::value, \
	"Invalid channel type for color format" \
)

#endif
