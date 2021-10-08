//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_TYPES_STATIC_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_STATIC_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/types/static_channels_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::types
{

template <typename Format>
using static_channels = decltype(static_channels_adl(
    std::declval<mizuiro::color::types::static_channels_ns::tag>(),
    mizuiro::color::format::make_tag_of<Format>()));

}

#endif
