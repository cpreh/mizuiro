//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/size_type.hpp>
#include <mizuiro/color/heterogenous_static.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/access/heterogenous.hpp>
#include <mizuiro/color/access/static.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/depth.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/stencil.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/depth.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/init/stencil.hpp>
#include <mizuiro/color/layout/depth_stencil.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/color/types/heterogenous.hpp>
#include <mizuiro/color/types/heterogenous_normal.hpp>
#include <mizuiro/color/types/static.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10_c.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/cstdint.hpp>
#include <mizuiro/detail/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	homogenous_depth_stencil
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef mizuiro::color::heterogenous_static<
		boost::mpl::vector2_c<
			mizuiro::size_type,
			24u,
			8u
		>,
		mizuiro::color::layout::depth_stencil
	> depth24_stencil8_format;

	typedef mizuiro::color::object<
		depth24_stencil8_format
	> depth24_stencil8_color;

	depth24_stencil8_color const test1(
		(mizuiro::color::init::depth() = static_cast<boost::uint32_t>(0x1E1FF))
		(mizuiro::color::init::stencil() = static_cast<boost::uint8_t>(0xF))
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::depth()
		)
		==
		static_cast<boost::uint32_t>(0x1E1FF)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::stencil()
		)
		==
		static_cast<boost::uint8_t>(0xF)
	);
}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	homogenous_rgb
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef mizuiro::color::heterogenous_static<
		boost::mpl::vector3_c<
			mizuiro::size_type,
			5u,
			6u,
			5u
		>,
		mizuiro::color::layout::rgb
	> rgb565_format;

	typedef mizuiro::color::object<
		rgb565_format
	> rgb565_color;

	rgb565_color const test1(
		(mizuiro::color::init::red() = static_cast<boost::uint8_t>(0x18))
		(mizuiro::color::init::green() = static_cast<boost::uint8_t>(0x35))
		(mizuiro::color::init::blue() = static_cast<boost::uint8_t>(0x15))
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::red()
		)
		==
		static_cast<boost::uint8_t>(0x18)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::green()
		)
		==
		static_cast<boost::uint8_t>(0x35)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::blue()
		)
		==
		static_cast<boost::uint8_t>(0x15)
	);
}
