//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/compare.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/operators.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int
main()
{
	typedef std::uint8_t channel_type;

	typedef mizuiro::color::object<
		mizuiro::color::format::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgb
		>
	> rgba_color;

	rgba_color test(
		(mizuiro::color::init::red() %= 1.0)
		(mizuiro::color::init::green() %= 0.3)
		(mizuiro::color::init::blue() %= 0.5)
	);

	test = test * 0.5;

	std::cout
		<< test
		<< '\n';

	test = test + test;

	std::cout
		<< test
		<< '\n';

	rgba_color const test2(
		(mizuiro::color::init::red() %= 0.5)
		(mizuiro::color::init::green() %= 0.15)
		(mizuiro::color::init::blue() %= 0.25)
	);

	if(
		mizuiro::color::compare(
			test,
			test2,
			[](
				channel_type const _a,
				channel_type const _b
			)
			{
				return
					_a
					==
					_b;
			}
		)
	)
		std::cout
			<< "equal\n";
}
