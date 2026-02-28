//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/no_init.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/r.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp> // NOLINT(misc-include-cleaner)
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

namespace
{

using channel_type = std::uint8_t;

using format = mizuiro::image::format::interleaved<
    mizuiro::image::dimension<2>,
    mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::r>>;

using store_type = mizuiro::image::store<format>;

using view_type =
    mizuiro::image::view<store_type::access, store_type::format, mizuiro::nonconst_tag>;

}

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("view operations", "[mizuiro]")
{
  store_type store(store_type::dim{1U, 1U}, mizuiro::no_init{});

  view_type view(store.view());

  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
  view[view_type::dim{0U, 0U}] = mizuiro::color::object<format::color_format>(
      // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      mizuiro::color::init::red() = channel_type{42}
  );

  CHECK(
      // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers,cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
      view[view_type::dim(0U, 0U)].get(mizuiro::color::channel::red()) == channel_type{42}
  );

  {
    auto it(view.begin());

    CHECK((*it).get(mizuiro::color::channel::red()) == channel_type{42});

    ++it;

    CHECK(it == view.end());

    --it;

    CHECK(it == view.begin());
  }

  CHECK(view.begin() + 1 == view.end());

  CHECK(view.end() - view.begin() == 1);
}

TEST_CASE("view fill", "[mizuiro]")
{
  store_type const store(
      store_type::dim{1U, 1U},
      [](store_type::view_type const &_view)
      {
        mizuiro::image::algorithm::fill_c(
            view_type(_view),
            mizuiro::color::object<format::color_format>(
                // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
                mizuiro::color::init::red() = channel_type{42}
                ),
            mizuiro::image::algorithm::uninitialized::yes);
      });

  CHECK(
      // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers,cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
      store.view()[store_type::dim(0U, 0U)].get(mizuiro::color::channel::red()) == channel_type{42}
  );
}

// NOLINTEND(bugprone-throwing-static-initialization,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
