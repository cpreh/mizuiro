//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/luminance.hpp>
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/color/operators/equal.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/clone.hpp>
#include <mizuiro/image/algorithm/equal.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"algorithm::clone",
	"[mizuiro]"
)
{
	typedef
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::l
	>
	homogenous_gray8;

	typedef
	mizuiro::color::object<
		homogenous_gray8
	>
	homogenous_gray8_color;

	typedef
	mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			2
		>,
		homogenous_gray8
	>
	format_2d_gray8;

	typedef
	mizuiro::image::store<
		format_2d_gray8
	>
	store_2d_gray8;

	store_2d_gray8 store(
		store_2d_gray8::dim(
			5u,
			5u
		),
		homogenous_gray8_color(
			mizuiro::color::init::luminance() %= 1.0
		)
	);

	store_2d_gray8 store2(
		mizuiro::image::algorithm::clone(
			store.view()
		)
	);

	CHECK(
		mizuiro::image::algorithm::equal(
			store.view(),
			store2.view()
		)
	);
}
