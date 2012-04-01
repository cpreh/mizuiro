//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/access/homogenous_normal.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/cstdint.hpp>
#include <mizuiro/detail/external_end.hpp>

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	empty_view
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			3
		>,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous_static<
				boost::uint8_t,
				mizuiro::color::layout::rgba
			>
		>
	> format_3d_rgba8;

	typedef mizuiro::image::store<
		format_3d_rgba8
	> store_3d_rgba8;

	store_3d_rgba8 store(
		store_3d_rgba8::dim::null()
	);

	typedef store_3d_rgba8::view_type view_3d_rgba8;

	{
		view_3d_rgba8 const view(
			store.view()
		);

		BOOST_REQUIRE(
			view.begin()
			== view.end()
		);
	}

	store = store_3d_rgba8(
		store_3d_rgba8::dim(
			0,
			1,
			2
		)
	);

	{
		view_3d_rgba8 const view(
			store.view()
		);

		BOOST_REQUIRE(
			view.begin()
			== view.end()
		);
	}

}
