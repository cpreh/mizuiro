//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_TYPES_CHANNEL_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_CHANNEL_VALUE_HPP_INCLUDED

#include <mizuiro/color/types/detail/channel_value.hpp>

namespace mizuiro::color::types
{

template <typename Format, typename Channel>
using channel_value = mizuiro::color::types::detail::channel_value<Format, Channel>::type;

}

#endif
