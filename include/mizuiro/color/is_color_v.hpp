//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_IS_COLOR_V_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_COLOR_V_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>

namespace mizuiro::color
{
template <typename T>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool is_color_v = mizuiro::color::is_color<T>::value;
}

#endif
