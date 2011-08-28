#include <mizuiro/image/format.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/access/homogenous_normal.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <boost/cstdint.hpp>
#include <boost/test/unit_test.hpp>

namespace
{
typedef
mizuiro::image::format
<
	mizuiro::image::dimension<2>,
	mizuiro::image::interleaved
	<
		mizuiro::color::homogenous_static
		<
			boost::uint8_t,
			mizuiro::color::layout::gray
		>
	>
>
format_2d;

typedef
mizuiro::image::store<format_2d>
store_2d;
}

BOOST_AUTO_TEST_CASE(
	iterator_position_test)
{
	store_2d field(
		store_2d::dim(
			2,
			2));

	store_2d::view_type const field_view =
		field.view();

	store_2d::view_type::iterator i =
		field_view.begin();

	BOOST_CHECK_EQUAL(
		mizuiro::image::iterator_position(
			field_view,
			i++),
		store_2d::dim(0,0));

	BOOST_CHECK(
		mizuiro::image::iterator_position(
			field_view,
			i++) == store_2d::dim(1,0));

	BOOST_CHECK(
		mizuiro::image::iterator_position(
			field_view,
			i++) == store_2d::dim(0,1));

	BOOST_CHECK(
		mizuiro::image::iterator_position(
			field_view,
			i++) == store_2d::dim(1,1));
}
