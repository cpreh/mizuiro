#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/cstdint.hpp>

BOOST_AUTO_TEST_CASE(
	empty_view
)
{
	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			3
		>,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous<
				boost::uint8_t,
				mizuiro::color::layout::rgba
			>
		>
	> format_3d_rgba8;

	typedef mizuiro::image::store<
		format_3d_rgba8
	> store_3d_rgba8;

	store_3d_rgba8 store(
		store_3d_rgba8::dim_type::null()
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
		store_3d_rgba8::dim_type(
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
