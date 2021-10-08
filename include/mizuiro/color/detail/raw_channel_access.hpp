//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_DETAIL_RAW_CHANNEL_ACCESS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_RAW_CHANNEL_ACCESS_HPP_INCLUDED

#include <mizuiro/const_raw_pointer.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/detail/copy_n.hpp>
#include <fcppt/cast/to_char_ptr.hpp>

namespace mizuiro::color::detail
{

template <typename ValueType>
struct raw_channel_access
{
  using value_type = ValueType;

  template <typename Pointer>
  static value_type read(Pointer const _data)
  {
    value_type ret;

    mizuiro::detail::copy_n(
        _data, sizeof(value_type), fcppt::cast::to_char_ptr<mizuiro::raw_pointer>(&ret));

    return ret;
  }

  template <typename Pointer>
  static void write(Pointer const _data, value_type const _ref)
  {
    mizuiro::detail::copy_n(
        fcppt::cast::to_char_ptr<mizuiro::const_raw_pointer>(&_ref), sizeof(value_type), _data);
  }
};

}

#endif
