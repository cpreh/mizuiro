//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_DEFINITELY_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DEFINITELY_HAS_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/format/has_channel_static.hpp>

namespace mizuiro::color::format
{

template <typename Format, typename Channel>
using definitely_has_channel = mizuiro::color::format::has_channel_static<Format, Channel>;

}

#endif
