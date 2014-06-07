//          Copyright Carl Philipp Reh 2009 - 2014.
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
#include <mizuiro/detail/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int main()
{
	typedef std::uint8_t channel_type;

	typedef mizuiro::color::format::homogenous_static<
		channel_type,
		mizuiro::color::layout::hsva
	> hsva_format;

	typedef mizuiro::color::object<
		hsva_format
	> hsva_object;

	hsva_object const source(
		(mizuiro::color::init::hue() %= 0.5)
		(mizuiro::color::init::saturation() %= 0.6)
		(mizuiro::color::init::value() %= 0.4)
		(mizuiro::color::init::alpha() %= 1.0)
	);

	typedef mizuiro::color::format::homogenous_static<
		channel_type,
		mizuiro::color::layout::rgba
	> rgba_format;

	typedef mizuiro::color::object<
		rgba_format
	> rgba_object;

	rgba_object const converted(
		mizuiro::color::convert<
			mizuiro::color::convert_static::converter,
			rgba_format
		>(
			source
		)
	);

	std::cout
		<< converted
		<< '\n';
}
