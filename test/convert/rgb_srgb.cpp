//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/compare.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/s_rgba.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <mizuiro/test/external_end.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cmath>
#include <mizuiro/detail/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	convert_rgb_srgb
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef
	float
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
			mizuiro::color::layout::s_rgba
		>
	>
	srgba_color;

	rgba_color const rgba(
		(mizuiro::color::init::red() %= 0.3)
		(mizuiro::color::init::blue() %= 0.2)
		(mizuiro::color::init::green() %= 0.5)
		(mizuiro::color::init::alpha() %= 0.9)
	);

	srgba_color const srgba(
		mizuiro::color::convert<
			mizuiro::color::convert_static::converter,
			srgba_color::format
		>(
			rgba
		)
	);

	rgba_color const rgba2(
		mizuiro::color::convert<
			mizuiro::color::convert_static::converter,
			rgba_color::format
		>(
			srgba
		)
	);

	BOOST_CHECK(
		mizuiro::color::compare(
			rgba,
			rgba2,
			[](
				channel_type const _val1,
				channel_type const _val2
			)
			{
				return
					std::abs(
						_val1
						-
						_val2
					)
					<
					0.001f;
			}
		)
	);
}
