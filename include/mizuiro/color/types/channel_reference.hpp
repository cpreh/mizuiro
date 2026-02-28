//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_TYPES_CHANNEL_REFERENCE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_CHANNEL_REFERENCE_HPP_INCLUDED

#include <mizuiro/color/types/detail/channel_reference.hpp>

namespace mizuiro::color::types
{

template <typename Access, typename Format, typename Channel, typename Constness>
using channel_reference =
    mizuiro::color::types::detail::channel_reference<Access, Format, Channel, Constness>::type;
}

#endif
