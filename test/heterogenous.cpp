//          Copyright Carl Philipp Reh 2009 - 2016.
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
#include <mizuiro/mpl/size_list.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <catch.hpp>
#include <cstdint>
#include <mizuiro/test/external_end.hpp>


TEST_CASE(
	"heterogenous luminance_alpha",
	"[mizuiro]"
)
{
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
		(mizuiro::color::init::luminance() = std::uint32_t{0x1E1FF})
		(mizuiro::color::init::alpha() = std::uint8_t{0xF})
	);

	CHECK(
		*test1.data()
		==
		std::uint32_t{0x1E1FF0F}
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::luminance()
		)
		==
		std::uint32_t{0x1E1FF}
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::alpha()
		)
		==
		std::uint8_t{0xF}
	);
}

TEST_CASE(
	"heterogenous rgb",
	"[mizuiro]"
)
{
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
		(mizuiro::color::init::red() = std::uint8_t{0x18})
		(mizuiro::color::init::green() = std::uint8_t{0x35})
		(mizuiro::color::init::blue() = std::uint8_t{0x15})
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::red()
		)
		==
		std::uint8_t{0x18}
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::green()
		)
		==
		std::uint8_t{0x35}
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::blue()
		)
		==
		std::uint8_t{0x15}
	);
}

TEST_CASE(
	"heterogenous raw",
	"[mizuiro]"
)
{
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
		(mizuiro::color::init::red() = std::uint8_t{0x18})
		(mizuiro::color::init::green() = std::uint8_t{0x35})
		(mizuiro::color::init::blue() = std::uint8_t{0x15})
	);

	CHECK(
		color.get(
			mizuiro::color::channel::red()
		)
		==
		std::uint8_t{0x18}
	);

	CHECK(
		color.get(
			mizuiro::color::channel::green()
		)
		==
		std::uint8_t{0x35}
	);

	CHECK(
		color.get(
			mizuiro::color::channel::blue()
		)
		==
		std::uint8_t{0x15}
	);
}
