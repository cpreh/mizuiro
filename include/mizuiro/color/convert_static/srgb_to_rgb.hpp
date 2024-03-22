//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_CONVERT_STATIC_SRGB_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_SRGB_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/srgb_to_rgb.hpp>
#include <mizuiro/color/space/rgb_fwd.hpp>
#include <mizuiro/color/space/srgb_fwd.hpp>
#include <mizuiro/color/types/space.hpp>
#include <fcppt/tag_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::convert_static
{

template <typename Dest, typename Src>
inline mizuiro::color::object<Dest> convert(fcppt::tag<Dest> const &, Src const &_src)
  requires(std::conjunction_v<
           std::is_same<mizuiro::color::types::space<Dest>, mizuiro::color::space::rgb>,
           std::is_same<
               mizuiro::color::types::space<typename Src::format>,
               mizuiro::color::space::srgb>>)
{
  return mizuiro::color::conversion::srgb_to_rgb<Dest>(_src);
}
}

#endif
