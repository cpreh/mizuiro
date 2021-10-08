//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_OPERATORS_EQUAL_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_EQUAL_HPP_INCLUDED

#include <mizuiro/color/compare.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/detail/equal.hpp>

namespace mizuiro::color
{

template <typename Color1, typename Color2>
bool operator==(Color1 const &_color1, Color2 const &_color2)
{
  static_assert(mizuiro::color::is_color<Color1>::value, "Color1 must be a color type");

  static_assert(mizuiro::color::is_color<Color2>::value, "Color2 must be a color type");

  return mizuiro::color::compare(_color1, _color2, mizuiro::detail::equal());
}

}

#endif
