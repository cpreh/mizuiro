//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/luminance.hpp>
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/clone.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/detail/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	algorithm_clone
)
{
MIZUIRO_DETAIL_POP_WARNING

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
		)
	);

	mizuiro::image::algorithm::fill_c(
		store.view(),
		homogenous_gray8_color(
			mizuiro::color::init::luminance() %= 1.0
		)
	);

	store_2d_gray8 store2(
		mizuiro::image::algorithm::clone(
			store.view()
		)
	);

	// TODO: Add equal algorithm!
}
