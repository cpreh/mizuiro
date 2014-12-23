//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/detail/external_end.hpp>


namespace
{

typedef
mizuiro::image::format::interleaved
<
	mizuiro::image::dimension<2>,
	mizuiro::color::format::homogenous_static
	<
		std::uint8_t,
		mizuiro::color::layout::l
	>
>
format_2d;

typedef
mizuiro::image::store
<
	format_2d
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
			2u,
			2u));

	store_2d::view_type const field_view =
		field.view();

	store_2d::view_type::iterator i =
		field_view.begin();

	BOOST_CHECK_EQUAL(
		mizuiro::image::iterator_position(
			field_view,
			i++),
		store_2d::dim(0u,0u));

	BOOST_CHECK(
		mizuiro::image::iterator_position(
			field_view,
			i++) == store_2d::dim(1u,0u));

	BOOST_CHECK(
		mizuiro::image::iterator_position(
			field_view,
			i++) == store_2d::dim(0u,1u));

	BOOST_CHECK(
		mizuiro::image::iterator_position(
			field_view,
			i++) == store_2d::dim(1u,1u));
}
