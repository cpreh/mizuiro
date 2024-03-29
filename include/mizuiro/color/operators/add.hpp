//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_OPERATORS_ADD_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_ADD_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/operators/detail/binary_op.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color
{

template <typename Color1, typename Color2>
mizuiro::color::object<typename Color1::format>
operator+(Color1 const &_color1, Color2 const &_color2)
{
  return mizuiro::color::operators::detail::binary_op<std::plus>(_color1, _color2);
}

}

#endif
