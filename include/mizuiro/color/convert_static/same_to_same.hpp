//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_CONVERT_STATIC_SAME_TO_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_SAME_TO_SAME_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/same_to_same.hpp>
#include <mizuiro/color/format/same_spaces.hpp>
#include <fcppt/tag_fwd.hpp>

namespace mizuiro::color::convert_static
{

template <typename Dest, typename Src>
inline mizuiro::color::object<Dest> convert(fcppt::tag<Dest> const &, Src const &_src)
  requires(mizuiro::color::format::same_spaces<Dest, typename Src::format>::value)
{
  return mizuiro::color::conversion::same_to_same<Dest>(_src);
}
}

#endif
