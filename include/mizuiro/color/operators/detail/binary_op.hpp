//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_BINARY_OP_HPP_INCLUDED

#include <mizuiro/decltype.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/format/get.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::operators::detail
{

template <template <typename> class Operation, typename Color1, typename Color2>
mizuiro::color::object<typename Color1::format>
binary_op(Color1 const &_color1, Color2 const &_color2)
{
  static_assert(
      std::is_same_v<typename Color1::format, typename Color2::format>,
      "Color1 and Color2 must use the same color format");

  static_assert(mizuiro::color::is_color<Color1>::value, "Color1 must be a color type");

  static_assert(mizuiro::color::is_color<Color2>::value, "Color2 must be a color type");

  using result_type = mizuiro::color::object<typename Color1::format>;

  result_type result(_color1);

  mizuiro::color::for_each_channel(
      _color1,
      [&result, &_color1, &_color2](auto const &_channel_inner)
      {
        using channel_value = mizuiro::color::types::
            channel_value<mizuiro::color::format::get<Color1>, MIZUIRO_DECLTYPE(_channel_inner)>;

        result.set(
            _channel_inner,
            static_cast<channel_value>(Operation<channel_value>()(
                _color1.get(_channel_inner), _color2.get(_channel_inner))));
      });

  return result;
}

}

#endif
