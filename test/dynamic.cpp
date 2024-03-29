//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_dynamic.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/color/format/detail/has_channel_constexpr.hpp>
#include <mizuiro/color/format/include/homogenous_dynamic.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/space/rgb.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <functional>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("dynamic heterogenous", "[mizuiro]")
{
  using color_uint8_4_format =
      mizuiro::color::format::homogenous_dynamic<std::uint8_t, mizuiro::color::space::rgb, 4>;

  static_assert(
      !mizuiro::color::format::detail::
          has_channel_constexpr<color_uint8_4_format, mizuiro::color::channel::red>::value,
      "has_channel should not be constexpr");

  color_uint8_4_format const rgba_format{mizuiro::color::layout::rgba{}};

  using color_uint8_4 = mizuiro::color::object<color_uint8_4_format>;

  using color_format_store = mizuiro::color::format::store<color_uint8_4_format>;

  color_format_store const rgba_format_store(std::cref(rgba_format));

  color_uint8_4 const test1(
      (mizuiro::color::init::red() =
           std::uint8_t{4})(mizuiro::color::init::green() = std::uint8_t{10})(
          mizuiro::color::init::blue() =
              std::uint8_t{20})(mizuiro::color::init::alpha() = std::uint8_t{45}),
      rgba_format_store);

  CHECK(test1.get(mizuiro::color::channel::red()) == std::uint8_t{4});

  CHECK(test1.get(mizuiro::color::channel::green()) == std::uint8_t{10});

  CHECK(test1.get(mizuiro::color::channel::blue()) == std::uint8_t{20});

  CHECK(test1.get(mizuiro::color::channel::alpha()) == std::uint8_t{45});
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
