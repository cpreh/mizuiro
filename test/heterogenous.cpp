//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/heterogenous_static.hpp>
#include <mizuiro/color/format/include/heterogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/luminance.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/la.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/mpl/size_list.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/test/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	heterogenous_luminance_alpha
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef
	mizuiro::color::format::heterogenous_static<
		mizuiro::mpl::size_list<
			24u,
			8u
		>,
		mizuiro::color::layout::la
	>
	luminance24_alpha8_format;

	typedef
	mizuiro::color::object<
		luminance24_alpha8_format
	>
	luminance24_alpha8_color;

	luminance24_alpha8_color const test1(
		(mizuiro::color::init::luminance() = static_cast<std::uint32_t>(0x1E1FF))
		(mizuiro::color::init::alpha() = static_cast<std::uint8_t>(0xF))
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::luminance()
		)
		==
		static_cast<std::uint32_t>(0x1E1FF)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::alpha()
		)
		==
		static_cast<std::uint8_t>(0xF)
	);
}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	heterogenous_rgb
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef mizuiro::color::format::heterogenous_static<
		mizuiro::mpl::size_list<
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
		(mizuiro::color::init::red() = static_cast<std::uint8_t>(0x18))
		(mizuiro::color::init::green() = static_cast<std::uint8_t>(0x35))
		(mizuiro::color::init::blue() = static_cast<std::uint8_t>(0x15))
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::red()
		)
		==
		static_cast<std::uint8_t>(0x18)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::green()
		)
		==
		static_cast<std::uint8_t>(0x35)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::blue()
		)
		==
		static_cast<std::uint8_t>(0x15)
	);
}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	heterogenous_raw
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef mizuiro::color::format::heterogenous_static<
		mizuiro::mpl::size_list<
			5u,
			6u,
			5u
		>,
		mizuiro::color::layout::rgb
	>
	rgb565_format;

	typedef
	mizuiro::color::object<
		rgb565_format
	>
	rgb565_color;

	rgb565_color const color(
		(mizuiro::color::init::red() = static_cast<std::uint8_t>(0x18))
		(mizuiro::color::init::green() = static_cast<std::uint8_t>(0x35))
		(mizuiro::color::init::blue() = static_cast<std::uint8_t>(0x15))
	);

	BOOST_CHECK(
		color.get(
			mizuiro::color::channel::red()
		)
		==
		static_cast<std::uint8_t>(0x18)
	);

	BOOST_CHECK(
		color.get(
			mizuiro::color::channel::green()
		)
		==
		static_cast<std::uint8_t>(0x35)
	);

	BOOST_CHECK(
		color.get(
			mizuiro::color::channel::blue()
		)
		==
		static_cast<std::uint8_t>(0x15)
	);
}
