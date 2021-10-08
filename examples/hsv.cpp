//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/hue.hpp>
#include <mizuiro/color/init/saturation.hpp>
#include <mizuiro/color/init/value.hpp>
#include <mizuiro/color/layout/hsva.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  using channel_type = std::uint8_t;

  using hsva_format =
      mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::hsva>;

  using hsva_object = mizuiro::color::object<hsva_format>;

  hsva_object const source(
      (mizuiro::color::init::hue() %=
       0.5) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::saturation() %=
       0.6) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::value() %=
       0.4) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::alpha() %=
       1.0) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  );

  using rgba_format =
      mizuiro::color::format::homogenous_static<channel_type, mizuiro::color::layout::rgba>;

  using rgba_object = mizuiro::color::object<rgba_format>;

  rgba_object const converted(
      mizuiro::color::convert<mizuiro::color::convert_static::converter, rgba_format>(source));

  std::cout << converted << '\n';
}
