//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  using channel = std::uint8_t;

  using rgba_color = mizuiro::color::object<
      mizuiro::color::format::homogenous_static<channel, mizuiro::color::layout::rgba>>;

  rgba_color const testcolor((mizuiro::color::init::red() = channel{42})(
      mizuiro::color::init::green() = channel{5})(mizuiro::color::init::blue() = channel{100})(
      mizuiro::color::init::alpha() = channel{53}));

  rgba_color const testcolor2(
      (mizuiro::color::init::red() %= 0.5)(mizuiro::color::init::blue() %= 0.3)(
          mizuiro::color::init::green() %= 0.1)(mizuiro::color::init::alpha() %= 1.0));

  std::cout << testcolor << ' ' << testcolor2 << '\n';
}
