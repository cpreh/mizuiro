//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/no_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/test/external_end.hpp>


BOOST_AUTO_TEST_CASE(
	homogenous_static
)
{
	typedef
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::l
	>
	format;

	typedef
	mizuiro::color::object<
		format
	>
	object;

	object foo{
		mizuiro::no_init{}
	};

	std::uint8_t const test(
		42u
	);

	foo.set(
		mizuiro::color::channel::luminance(),
		test
	);

	BOOST_CHECK_EQUAL(
		foo.get(
			mizuiro::color::channel::luminance()
		),
		test
	);
}
