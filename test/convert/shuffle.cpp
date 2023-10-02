//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/bgra.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("convert shuffle", "[mizuiro]")
{
  using channel_type = std::uint8_t;

  using rgba_color = mizuiro::color::object<
      mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::rgba>>;

  using bgra_color = mizuiro::color::object<
      mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::bgra>>;

  rgba_color const rgba(
      (mizuiro::color::init::red() =
           channel_type{
               23}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::blue() =
           channel_type{
               42}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::green() =
           channel_type{
               100}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::alpha() =
           channel_type{
               150}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  );

  bgra_color const bgra(
      mizuiro::color::convert<mizuiro::color::convert_static::converter, bgra_color::format>(rgba));

  CHECK(bgra.get(mizuiro::color::channel::red()) == channel_type{23});

  CHECK(bgra.get(mizuiro::color::channel::green()) == channel_type{100});

  CHECK(bgra.get(mizuiro::color::channel::blue()) == channel_type{42});

  CHECK(bgra.get(mizuiro::color::channel::alpha()) == channel_type{150});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
