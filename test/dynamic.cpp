//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_dynamic.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/color/format/include/homogenous_dynamic.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/space/rgb.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <functional>
#include <mizuiro/test/external_end.hpp>


TEST_CASE(
	"dynamic heterogenous",
	"[mizuiro]"
)
{
	typedef
	mizuiro::color::format::homogenous_dynamic<
		std::uint8_t,
		mizuiro::color::space::rgb,
		4
	>
	color_uint8_4_format;

	color_uint8_4_format const rgba_format{
		mizuiro::color::layout::rgba{}
	};

	typedef
	mizuiro::color::object<
		color_uint8_4_format
	>
	color_uint8_4;

	typedef
	mizuiro::color::format::store<
		color_uint8_4_format
	>
	color_format_store;

	color_format_store const rgba_format_store(
		std::cref(
			rgba_format
		)
	);

	color_uint8_4 const test1(
		(
			mizuiro::color::init::red() = std::uint8_t{4}
		)(
			mizuiro::color::init::green() = std::uint8_t{10}
		)(
			mizuiro::color::init::blue() = std::uint8_t{20}
		)(
			mizuiro::color::init::alpha() = std::uint8_t{45}
		)
		,
		rgba_format_store
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::red()
		)
		==
		std::uint8_t{4}
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::green()
		)
		==
		std::uint8_t{10}
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::blue()
		)
		==
		std::uint8_t{20}
	);

	CHECK(
		test1.get(
			mizuiro::color::channel::alpha()
		)
		==
		std::uint8_t{45}
	);
}
