//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/const_view.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <cstdint>
#include <exception>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
try
{
  using format = mizuiro::image::format::interleaved<
      mizuiro::image::dimension<3>,
      mizuiro::color::format::homogenous_static<std::uint8_t, mizuiro::color::layout::rgba>>;

  using store = mizuiro::image::store<format>;

  using view_type = store::view_type;

  store const img{
      store::dim(3U, 2U, 1U),
      [](view_type const &_view)
      {
        for (auto const &color : _view)
        {
          color.set(
              // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
              mizuiro::color::channel::red(), std::uint8_t{10}
          );
        }
      }};

  using const_view_type = mizuiro::image::const_view<view_type>;

  const_view_type const const_view{img.view()};

  for (auto const &color : const_view)
  {
    std::cout << static_cast<int>(color.get(mizuiro::color::channel::red())) << ' ';
  }

  std::cout << '\n';
}
catch(std::exception const &_error)
{
  std::cerr << _error.what() << '\n';
  return EXIT_FAILURE;
}
