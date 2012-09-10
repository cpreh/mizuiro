//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/array.hpp>
#include <mizuiro/const_tag.hpp>
#include <mizuiro/raw_value.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/homogenous_raw.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous_raw.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iterator>
#include <boost/test/unit_test.hpp>
#include <boost/cstdint.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace
{

typedef mizuiro::color::homogenous_static<
	boost::uint32_t,
	mizuiro::color::layout::rgb
> rgb32_format;

}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	data_normal
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef mizuiro::color::homogenous_static<
		boost::uint32_t,
		mizuiro::color::layout::rgb
	> rgb32_format;

	typedef mizuiro::color::object<
		rgb32_format
	> rgb32_color;

	rgb32_color color;

	BOOST_CHECK(
		std::distance(
			color.data(),
			color.data_end()
		)
		== 3
	);
}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	data_raw
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef mizuiro::array<
		mizuiro::raw_value,
		3 * sizeof(boost::uint32_t)
	>::type rgb32_raw_array;

	typedef mizuiro::color::proxy<
		mizuiro::access::raw,
		rgb32_format,
		mizuiro::const_tag
	> rgb32_proxy;

	rgb32_raw_array const raw_array = {{
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	}};

	rgb32_proxy const proxy(
		raw_array.data()
	);

	BOOST_CHECK(
		std::distance(
			proxy.data(),
			proxy.data_end()
		)
		== 3 * sizeof(boost::uint32_t)
	);
}
