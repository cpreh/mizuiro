//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_IS_RAW_VIEW_V_HPP_INCLUDED
#define MIZUIRO_IMAGE_IS_RAW_VIEW_V_HPP_INCLUDED

#include <mizuiro/image/is_raw_view.hpp>

namespace mizuiro::image
{

template <typename View>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool is_raw_view_v = mizuiro::image::is_raw_view<View>::value;

}

#endif
