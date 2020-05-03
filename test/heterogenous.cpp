//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_list.hpp>
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
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"heterogenous luminance_alpha",
	"[mizuiro]"
)
{
	using
	luminance24_alpha8_format
	=
	mizuiro::color::format::heterogenous_static<
		mizuiro::size_list<
			24U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			8U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		>,
		mizuiro::color::layout::la
	>;

	using
	luminance24_alpha8_color
	=
	mizuiro::color::object<
		luminance24_alpha8_format
	>;

	luminance24_alpha8_color const test1(
		(mizuiro::color::init::luminance() = std::uint32_t{0x1E1FF}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		(mizuiro::color::init::alpha() = std::uint8_t{0xF}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		*test1.data()
		==
		std::uint32_t{0x1E1FF0F} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::luminance()
		)
		==
		std::uint32_t{0x1E1FF} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::alpha()
		)
		==
		std::uint8_t{0xF} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}

TEST_CASE(
	"heterogenous rgb",
	"[mizuiro]"
)
{
	using
	rgb565_format
	=
	mizuiro::color::format::heterogenous_static<
		mizuiro::size_list<
			5U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			6U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			5U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		>,
		mizuiro::color::layout::rgb
	>;

	using
	rgb565_color
	=
	mizuiro::color::object<
		rgb565_format
	>;

	rgb565_color const test1(
		(mizuiro::color::init::red() = std::uint8_t{0x18}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		(mizuiro::color::init::green() = std::uint8_t{0x35}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		(mizuiro::color::init::blue() = std::uint8_t{0x15}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::red()
		)
		==
		std::uint8_t{0x18} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::green()
		)
		==
		std::uint8_t{0x35} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::blue()
		)
		==
		std::uint8_t{0x15} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}

TEST_CASE(
	"heterogenous raw",
	"[mizuiro]"
)
{
	using
	rgb565_format
	=
	mizuiro::color::format::heterogenous_static<
		mizuiro::size_list<
			5U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			6U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			5U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		>,
		mizuiro::color::layout::rgb
	>;

	using
	rgb565_color
	=
	mizuiro::color::object<
		rgb565_format
	>;

	rgb565_color const color(
		(mizuiro::color::init::red() = std::uint8_t{0x18}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		(mizuiro::color::init::green() = std::uint8_t{0x35}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		(mizuiro::color::init::blue() = std::uint8_t{0x15}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		color.get(
			mizuiro::color::channel::red()
		)
		==
		std::uint8_t{0x18} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		color.get(
			mizuiro::color::channel::green()
		)
		==
		std::uint8_t{0x35} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		color.get(
			mizuiro::color::channel::blue()
		)
		==
		std::uint8_t{0x15} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}
