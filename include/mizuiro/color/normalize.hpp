//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED

#include <mizuiro/color/is_color_v.hpp>
#include <mizuiro/color/access/channel_max.hpp>
#include <mizuiro/color/access/channel_min.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color
{

template <typename Float, typename Channel, typename Color>
Float normalize(Color const &_color, Channel const &_channel)
{
  static_assert(mizuiro::color::is_color_v<Color>, "Color must be a color type");

  static_assert(std::is_floating_point_v<Float>, "Floating must be a floating point type");

  return (static_cast<Float>(_color.get(_channel)) -
          static_cast<Float>(mizuiro::color::access::channel_min<typename Color::format>(
              _color.format_store(), _channel))) /
         (static_cast<Float>(mizuiro::color::access::channel_max<typename Color::format>(
              _color.format_store(), _channel)) -
          static_cast<Float>(mizuiro::color::access::channel_min<typename Color::format>(
              _color.format_store(), _channel)));
}

}

#endif
