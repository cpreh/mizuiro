//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/empty.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <mizuiro/test/external_end.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/detail/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	empty_view
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			3
		>,
		mizuiro::color::format::homogenous_static<
			std::uint8_t,
			mizuiro::color::layout::rgba
		>
	> format_3d_rgba8;

	typedef mizuiro::image::store<
		format_3d_rgba8
	> store_3d_rgba8;

	store_3d_rgba8 store{
		mizuiro::empty{}
	};

	typedef store_3d_rgba8::view_type view_3d_rgba8;

	{
		view_3d_rgba8 const view(
			store.view()
		);

		BOOST_CHECK(
			view.begin()
			==
			view.end()
		);
	}
}
