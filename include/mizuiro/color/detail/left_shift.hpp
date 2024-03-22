//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_DETAIL_LEFT_SHIFT_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_LEFT_SHIFT_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::detail
{

template <typename Type, mizuiro::size_type Count>
constexpr Type left_shift()
  requires(Count == static_cast<mizuiro::size_type>(std::numeric_limits<Type>::digits))
{
  return ~Type{0};
}

template <typename Type, mizuiro::size_type Count>
constexpr Type left_shift()
  requires(Count < static_cast<mizuiro::size_type>(std::numeric_limits<Type>::digits))
{
  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_VC_WARNING(4554)
  return (Type{1U} << Count) - Type{1U};
  FCPPT_PP_POP_WARNING
}
}

#endif
