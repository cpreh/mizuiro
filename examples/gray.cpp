//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/for_each.hpp>
#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

int main()
{
  using format = mizuiro::image::format::interleaved<
      mizuiro::image::dimension<2>,
      mizuiro::color::format::homogenous_static<std::uint8_t, mizuiro::color::layout::l>>;

  using store = mizuiro::image::store<format>;

  using view_type = store::view_type;

  store const img{
      store::dim(
          32U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
          64U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
          ),
      [](view_type const &_view)
      {
        mizuiro::image::algorithm::for_each(
            _view,
            [](auto const &_color)
            {
              _color.set(
                  mizuiro::color::channel::luminance(),
                  42 // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
              );
            },
            mizuiro::image::algorithm::make_iterator_identity{},
            mizuiro::image::algorithm::uninitialized::yes);
      }};
}
