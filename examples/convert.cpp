//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/layout/alpha.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>

int main()
{
	typedef boost::uint8_t channel_type;

	typedef mizuiro::color::object<
		mizuiro::color::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	> rgba_color;

	typedef mizuiro::color::object<
		mizuiro::color::homogenous_static<
			channel_type,
			mizuiro::color::layout::gray
		>
	> luminance_color;

	typedef mizuiro::color::object<
		mizuiro::color::homogenous_static<
			channel_type,
			mizuiro::color::layout::alpha
		>
	> alpha_color;

	luminance_color test_luminance(
		(mizuiro::color::init::luminance = static_cast<channel_type>(42))
	);

	rgba_color const test_rgb(
		mizuiro::color::convert<
			rgba_color::format
		>(
			test_luminance
		)
	);

	std::cout
		<< "luminance value was: "
		<< test_luminance
		<< " and was converted to"
		<< test_rgb
		<< '\n';

	typedef
		mizuiro::color::object
		<
			mizuiro::color::homogenous_static
			<
				float,
				mizuiro::color::layout::rgba
			>
		> rgba_float_color;

	rgba_float_color test_float
	(
		mizuiro::color::convert
		<
			rgba_float_color::format
		>
		(
			test_rgb
		)
	);

	std::cout
		<< "converted the rgb value to floats: "
		<< test_float
		<< '\n';

	luminance_color test_luminance2(
		mizuiro::color::convert<
			luminance_color::format
		>
		(
			test_float
		)
	);

	std::cout
		<< "converted back to luminance: "
		<< test_luminance2
		<< '\n';

	alpha_color const test_alpha(
		(mizuiro::color::init::alpha %= 0.5)
	);

	std::cout
		<< "alpha converted to rgba: "
		<< mizuiro::color::convert<
			rgba_float_color::format
		>(
			test_alpha
		)
		<< '\n';
}
