//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_DETAIL_SAME_CHANNEL_VALUE_TYPE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DETAIL_SAME_CHANNEL_VALUE_TYPE_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::format::detail
{

template <typename Format1, typename Format2, typename Channel>
using same_channel_value_type = std::is_same<
    mizuiro::color::types::channel_value<Format1, Channel>,
    mizuiro::color::types::channel_value<Format2, Channel>>;

}

#endif
