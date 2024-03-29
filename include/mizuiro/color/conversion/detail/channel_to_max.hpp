//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MAX_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_CHANNEL_TO_MAX_HPP_INCLUDED

#include <mizuiro/color/access/channel_max.hpp>

namespace mizuiro::color::conversion::detail
{

template <typename Channel, typename Color>
inline void channel_to_max(Color &_color, Channel const &_channel)
{
  _color.set(
      _channel,
      mizuiro::color::access::channel_max<typename Color::format>(_color.format_store(), _channel));
}

}

#endif
