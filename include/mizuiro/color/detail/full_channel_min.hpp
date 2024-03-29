//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_DETAIL_FULL_CHANNEL_MIN_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_FULL_CHANNEL_MIN_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::detail
{

template <typename Type>
inline Type full_channel_min()
  requires(std::is_integral_v<Type>)
{
  return std::numeric_limits<Type>::min();
}

template <typename Type>
inline Type full_channel_min()
  requires(std::is_floating_point_v<Type>)
{
  return static_cast<Type>(0);
}

}

#endif
