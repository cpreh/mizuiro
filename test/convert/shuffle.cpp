//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
#include <mizuiro/color/layout/bgra.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <catch.hpp>
#include <cstdint>
#include <mizuiro/test/external_end.hpp>


TEST_CASE(
	"convert shuffle",
	"[mizuiro]"
)
{
	typedef
	std::uint8_t
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
			mizuiro::color::layout::bgra
		>
	>
	bgra_color;

	rgba_color const rgba(
		(mizuiro::color::init::red() = channel_type{23})
		(mizuiro::color::init::blue() = channel_type{42})
		(mizuiro::color::init::green() = channel_type{100})
		(mizuiro::color::init::alpha() = channel_type{150})
	);

	bgra_color const bgra(
		mizuiro::color::convert<
			mizuiro::color::convert_static::converter,
			bgra_color::format
		>(
			rgba
		)
	);

	CHECK(
		bgra.get(
			mizuiro::color::channel::red()
		)
		==
		channel_type{23}
	);

	CHECK(
		bgra.get(
			mizuiro::color::channel::green()
		)
		==
		channel_type{100}
	);

	CHECK(
		bgra.get(
			mizuiro::color::channel::blue()
		)
		==
		channel_type{42}
	);

	CHECK(
		bgra.get(
			mizuiro::color::channel::alpha()
		)
		==
		channel_type{150}
	);
}
