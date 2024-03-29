//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/no_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/detail/has_channel_constexpr.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/layout/l.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>

FCPPT_CATCH_BEGIN
// NOLINTBEGIN(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)

TEST_CASE("homogenous static", "[mizuirp]")
{
  using format = mizuiro::color::format::homogenous_static<std::uint8_t, mizuiro::color::layout::l>;

  static_assert(
      mizuiro::color::format::detail::
          has_channel_constexpr<format, mizuiro::color::channel::luminance>::value,
      "has_channel should be constexpr");

  using object = mizuiro::color::object<format>;

  object foo{mizuiro::no_init{}};

  std::uint8_t const test(
      42U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  );

  foo.set(mizuiro::color::channel::luminance(), test);

  CHECK(foo.get(mizuiro::color::channel::luminance()) == test);
}

// NOLINTEND(misc-const-correctness,cert-err58-cpp,fuchsia-statically-constructed-objects,misc-use-anonymous-namespace,cppcoreguidelines-avoid-do-while)
FCPPT_CATCH_END
