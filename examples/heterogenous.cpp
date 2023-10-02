//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mizuiro/size_list.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/heterogenous_static.hpp>
#include <mizuiro/color/format/include/heterogenous_static.hpp> // NOLINT(misc-include-cleaner)
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/luminance.hpp>
#include <mizuiro/color/layout/la.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>

int main()
{
  using l24_a8_format = mizuiro::color::format::heterogenous_static<
      mizuiro::size_list<
          24U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
          8U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
          >,
      mizuiro::color::layout::la>;

  using l24_a8_color = mizuiro::color::object<l24_a8_format>;

  l24_a8_color const test1(
      (mizuiro::color::init::luminance() =
           std::uint32_t{
               0x1FF}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
      (mizuiro::color::init::alpha() =
           std::uint8_t{
               0xF}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  );

  std::cout << std::hex << test1 << '\n';
}
