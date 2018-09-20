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
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	std::uint8_t
	channel_type;

	typedef
	mizuiro::color::object<
		mizuiro::color::format::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	>
	rgba_color;

	typedef
	mizuiro::color::object<
		mizuiro::color::format::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgb
		>
	>
	rgb_color;

	rgba_color const test_rgba(
		(mizuiro::color::init::red() = channel_type{42})
		(mizuiro::color::init::blue() = channel_type{10})
		(mizuiro::color::init::green() = channel_type{99})
		(mizuiro::color::init::alpha() = channel_type{50})
	);

	rgb_color const test_rgb(
		mizuiro::color::convert<
			mizuiro::color::convert_static::converter,
			rgb_color::format
		>(
			test_rgba
		)
	);

	std::cout
		<< "rgba value was: "
		<< test_rgba
		<< " and was converted to rgb: "
		<< test_rgb
		<< '\n';

	typedef
	mizuiro::color::object<
		mizuiro::color::format::homogenous_static<
			float,
			mizuiro::color::layout::rgba
		>
	>
	rgba_float_color;

	rgba_float_color const test_rgba_float(
		mizuiro::color::convert<
			mizuiro::color::convert_static::converter,
			rgba_float_color::format
		>(
			test_rgb
		)
	);

	std::cout
		<< "converted the rgb value to rgba floats: "
		<< test_rgba_float
		<< '\n';
}
