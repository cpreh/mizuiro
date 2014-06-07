//          Copyright Carl Philipp Reh 2009 - 2014.
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
#include <mizuiro/detail/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int
main()
{
	typedef std::uint8_t channel;

	typedef mizuiro::color::object<
		mizuiro::color::format::homogenous_static<
			channel,
			mizuiro::color::layout::rgba
		>
	> rgba_color;

	rgba_color const testcolor(
		(mizuiro::color::init::red() = static_cast<channel>(42))
		(mizuiro::color::init::green() = static_cast<channel>(5))
		(mizuiro::color::init::blue() = static_cast<channel>(100))
		(mizuiro::color::init::alpha() = static_cast<channel>(53))
	);

	rgba_color const testcolor2(
		(mizuiro::color::init::red() %= 0.5)
		(mizuiro::color::init::blue() %= 0.3)
		(mizuiro::color::init::green() %= 0.1)
		(mizuiro::color::init::alpha() %= 1.0)
	);

	std::cout
		<< testcolor
		<< ' '
		<< testcolor2
		<< '\n';
}
