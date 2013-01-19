//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/static.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/static.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/access/interleaved.hpp>
#include <mizuiro/image/types/interleaved.hpp>
#include <mizuiro/image/types/interleaved_normal.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <boost/test/unit_test.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace
{

typedef
mizuiro::image::interleaved
<
	mizuiro::image::dimension<2>,
	mizuiro::color::homogenous_static
	<
		boost::uint8_t,
		mizuiro::color::layout::gray
	>
>
format_2d;

typedef
mizuiro::image::store
<
	format_2d,
	mizuiro::access::normal
>
store_2d;
}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	iterator_position_test)
{
MIZUIRO_DETAIL_POP_WARNING

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
