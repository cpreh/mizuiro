//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/layout/hsva.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>

int main()
{
	typedef boost::uint8_t channel_type;

	typedef mizuiro::color::homogenous_static<
		channel_type,
		mizuiro::color::layout::hsva
	> hsva_format;

	typedef mizuiro::color::object<
		hsva_format
	> hsva_object;

	hsva_object const source(
		(mizuiro::color::init::hue %= 0.5)
		(mizuiro::color::init::saturation %= 0.6)
		(mizuiro::color::init::value %= 0.4)
		(mizuiro::color::init::alpha %= 1.0)
	);

	typedef mizuiro::color::homogenous_static<
		channel_type,
		mizuiro::color::layout::rgba
	> rgba_format;

	typedef mizuiro::color::object<
		rgba_format
	> rgba_object;

	rgba_object const converted(
		mizuiro::color::convert<
			rgba_format
		>(
			source
		)
	);

	std::cout
		<< converted
		<< '\n';
}
