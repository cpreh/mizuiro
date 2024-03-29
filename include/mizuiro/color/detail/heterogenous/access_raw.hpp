//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_DETAIL_HETEROGENOUS_ACCESS_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HETEROGENOUS_ACCESS_RAW_HPP_INCLUDED

#include <mizuiro/const_raw_pointer.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/color/detail/heterogenous/access_normal.hpp>
#include <mizuiro/color/detail/heterogenous/bits.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/copy_n.hpp>
#include <mizuiro/detail/uint_least.hpp>
#include <fcppt/cast/to_char_ptr.hpp>

namespace mizuiro::color::detail::heterogenous
{

template <typename Format, typename Channel>
class access_raw
{
private:
  using access_normal = mizuiro::color::detail::heterogenous::access_normal<Format, Channel>;

  using value_type = mizuiro::color::types::channel_value<Format, Channel>;

  using color_uint = mizuiro::detail::uint_least<
      mizuiro::color::detail::heterogenous::bits<typename Format::channel_bits>>;

public:
  static value_type read(mizuiro::const_raw_pointer const _data)
  {
    color_uint temp;

    mizuiro::detail::copy_n(
        _data, sizeof(color_uint), fcppt::cast::to_char_ptr<mizuiro::raw_pointer>(&temp));

    return access_normal::read(&temp);
  }

  static void write(mizuiro::raw_pointer const _data, value_type const _value)
  {
    color_uint temp;

    mizuiro::detail::copy_n(
        _data, sizeof(color_uint), fcppt::cast::to_char_ptr<mizuiro::raw_pointer>(&temp));

    access_normal::write(&temp, _value);

    mizuiro::detail::copy_n(
        fcppt::cast::to_char_ptr<mizuiro::const_raw_pointer>(&temp), sizeof(color_uint), _data);
  }
};

}

#endif
