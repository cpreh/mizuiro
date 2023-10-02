//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED
#define MIZUIRO_COLOR_OUTPUT_HPP_INCLUDED

#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/is_color_v.hpp>
#include <mizuiro/color/format/get.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/promote_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color
{

template <typename Ch, typename Traits, typename Color>
std::enable_if_t<mizuiro::color::is_color_v<Color>, std::basic_ostream<Ch, Traits> &>
operator<<(std::basic_ostream<Ch, Traits> &_stream, Color const &_color)
{
  _stream << _stream.widen('(');

  mizuiro::color::for_each_channel(
      _color,
      [&_color, &_stream](auto const _channel)
      {
        _stream << static_cast<mizuiro::detail::promote_type<mizuiro::color::types::channel_value<
                       mizuiro::color::format::get<Color>,
                       std::remove_const_t<decltype(_channel)>>>>(_color.get(_channel))
                <<
            // FIXME
            _stream.widen(',');
      });

  _stream << _stream.widen(')');

  return _stream;
}
}

#endif
