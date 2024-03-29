//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_SAME_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_SAME_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/layout/detail/has_all_channels.hpp>
#include <mizuiro/color/types/static_channels.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::format
{

template <typename Format1, typename Format2>
using same_channels = std::conjunction<
    mizuiro::color::layout::detail::has_all_channels<
        mizuiro::color::types::static_channels<Format1>,
        mizuiro::color::types::static_channels<Format2>>,
    mizuiro::color::layout::detail::has_all_channels<
        mizuiro::color::types::static_channels<Format2>,
        mizuiro::color::types::static_channels<Format1>>>;

}

#endif
