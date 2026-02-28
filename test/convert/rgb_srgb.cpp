//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/color/compare.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/s_rgba.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cmath>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(bugprone-throwing-static-initialization,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("convert rgb_srgb", "[mizuiro]")
{
  using channel_type = float;

  using rgba_color = mizuiro::color::object<
      mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::rgba>>;

  using srgba_color = mizuiro::color::object<
      mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::s_rgba>>;

  rgba_color const rgba(
      (mizuiro::color::init::red() %=
       0.3) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::blue() %=
       0.2) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::green() %=
       0.5) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::alpha() %=
       0.9) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  );

  srgba_color const srgba(
      mizuiro::color::convert<mizuiro::color::convert_static::converter, srgba_color::format>(
          rgba));

  rgba_color const rgba2(
      mizuiro::color::convert<mizuiro::color::convert_static::converter, rgba_color::format>(
          srgba));

  CHECK(mizuiro::color::compare(
      rgba,
      rgba2,
      [](channel_type const _val1, channel_type const _val2)
      {
        return std::abs(_val1 - _val2) <
               0.001F; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      }));
}

// NOLINTEND(bugprone-throwing-static-initialization,misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
