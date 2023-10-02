//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/layout/bgra.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/linear_view_impl.hpp>
#include <mizuiro/image/algorithm/can_copy_v.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace
{

using format_3d_rgba8 = mizuiro::image::format::interleaved<
    mizuiro::image::dimension<3>,
    mizuiro::color::format::homogenous_static<std::uint8_t, mizuiro::color::layout::rgba>>;

using format_3d_bgra8 = mizuiro::image::format::interleaved<
    mizuiro::image::dimension<3>,
    mizuiro::color::format::homogenous_static<std::uint8_t, mizuiro::color::layout::bgra>>;

using format_2d_bgra8 = mizuiro::image::format::interleaved<
    mizuiro::image::dimension<2>,
    mizuiro::color::format::homogenous_static<std::uint8_t, mizuiro::color::layout::bgra>>;

using format_2d_bgra_f = mizuiro::image::format::interleaved<
    mizuiro::image::dimension<2>,
    mizuiro::color::format::homogenous_static<float, mizuiro::color::layout::bgra>>;

using format_2d_rgb8 = mizuiro::image::format::interleaved<
    mizuiro::image::dimension<2>,
    mizuiro::color::format::homogenous_static<float, mizuiro::color::layout::rgb>>;

}

int main()
{
  using view_3d_bgra8 = ::mizuiro::image::
      linear_view<::mizuiro::access::normal, ::format_3d_bgra8, ::mizuiro::nonconst_tag>;

  using view_3d_rgba8 = ::mizuiro::image::
      linear_view<::mizuiro::access::normal, ::format_3d_rgba8, ::mizuiro::nonconst_tag>;

  // bgra8 and rgba8 should be compatible to each other
  static_assert(::mizuiro::image::algorithm::can_copy_v<view_3d_bgra8, view_3d_rgba8>);

  using view_2d_bgra8 = ::mizuiro::image::
      linear_view<::mizuiro::access::normal, ::format_2d_bgra8, ::mizuiro::nonconst_tag>;

  using view_2d_bgra_f = ::mizuiro::image::
      linear_view<::mizuiro::access::normal, ::format_2d_bgra_f, ::mizuiro::nonconst_tag>;

  // bgra8 and bgra float should not be compatible
  static_assert(!::mizuiro::image::algorithm::can_copy_v<view_2d_bgra8, view_2d_bgra_f>);

  using view_2d_rgb8 = ::mizuiro::image::
      linear_view<::mizuiro::access::normal, ::format_2d_rgb8, ::mizuiro::nonconst_tag>;

  // bgra8 and rgb8 should not be compatible
  static_assert(!::mizuiro::image::algorithm::can_copy_v<view_2d_bgra8, view_2d_rgb8>);
}
