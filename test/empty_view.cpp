//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/empty.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("empty view", "[mizuiro]")
{
  using format_3d_rgba8 = mizuiro::image::format::interleaved<
      mizuiro::image::dimension<3>,
      mizuiro::color::format::homogenous_static<std::uint8_t, mizuiro::color::layout::rgba>>;

  using store_3d_rgba8 = mizuiro::image::store<format_3d_rgba8>;

  store_3d_rgba8 store{mizuiro::empty{}};

  using view_3d_rgba8 = store_3d_rgba8::view_type;

  {
    view_3d_rgba8 const view(store.view());

    CHECK(view.begin() == view.end());
  }
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
