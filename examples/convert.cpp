//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/access/homogenous.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/static.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/static.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int
main()
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
			mizuiro::color::layout::rgb
		>
	> rgb_color;

	rgba_color const test_rgba(
		(mizuiro::color::init::red() = static_cast<channel_type>(42))
		(mizuiro::color::init::blue() = static_cast<channel_type>(10))
		(mizuiro::color::init::green() = static_cast<channel_type>(99))
		(mizuiro::color::init::alpha() = static_cast<channel_type>(50))
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

	typedef mizuiro::color::object<
		mizuiro::color::homogenous_static<
			float,
			mizuiro::color::layout::rgba
		>
	> rgba_float_color;

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
