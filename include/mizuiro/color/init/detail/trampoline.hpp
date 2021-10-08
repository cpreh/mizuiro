//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_TRAMPOLINE_HPP_INCLUDED

#include <mizuiro/color/channel/undefined_fwd.hpp>
#include <mizuiro/color/init/detail/channel_percentage.hpp>
#include <mizuiro/color/init/detail/channel_value.hpp>
#include <mizuiro/color/init/detail/make_values.hpp>
#include <mizuiro/color/init/detail/values.hpp>
#include <fcppt/tuple/make.hpp>
#include <fcppt/tuple/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::init::detail
{

template <typename Channel>
struct trampoline
{
  static_assert(
      !std::is_same_v<Channel, mizuiro::color::channel::undefined>,
      "Can't initialize undefined channels");

  template <typename Value>
  // NOLINTNEXTLINE(cppcoreguidelines-c-copy-assignment-signature,misc-unconventional-assign-operator)
  inline mizuiro::color::init::detail::values<
      fcppt::tuple::object<mizuiro::color::init::detail::channel_value<Value, Channel>>>
  operator=(Value const &_value) const
  {
    return mizuiro::color::init::detail::make_values(fcppt::tuple::make(
        mizuiro::color::init::detail::channel_value<Value, Channel>(_value, Channel())));
  }

  template <typename Value>
  inline mizuiro::color::init::detail::values<
      fcppt::tuple::object<mizuiro::color::init::detail::channel_percentage<Value, Channel>>>
  operator%=(Value const &_value) const
  {
    static_assert(
        std::is_floating_point_v<Value>,
        "Arguments must be of floating point type for '%=' initialization");

    return mizuiro::color::init::detail::make_values(fcppt::tuple::make(
        mizuiro::color::init::detail::channel_percentage<Value, Channel>(_value, Channel())));
  }
};

}

#endif
