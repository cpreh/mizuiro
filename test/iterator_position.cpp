//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/no_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace
{

using
format_2d
=
mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::l
	>
>;

using
store_2d
=
mizuiro::image::store<
	format_2d
>;

}

FCPPT_CATCH_BEGIN

TEST_CASE(
	"iterator position",
	"[mizuiro]"
)
{
	store_2d field{
		store_2d::dim{
			2U,
			2U
		},
		mizuiro::no_init{}
	};

	store_2d::view_type const field_view{
		field.view()
	};

	store_2d::view_type::iterator it{
		field_view.begin()
	};

	REQUIRE(
		mizuiro::image::iterator_position(
			field_view,
			it++
		)
		==
		store_2d::dim(
			0U,
			0U
		)
	);

	REQUIRE(
		mizuiro::image::iterator_position(
			field_view,
			it++
		)
		==
		store_2d::dim(
			1U,
			0U
		)
	);

	REQUIRE(
		mizuiro::image::iterator_position(
			field_view,
			it++
		)
		==
		store_2d::dim(
			0U,
			1U
		)
	);

	REQUIRE(
		mizuiro::image::iterator_position(
			field_view,
			it++
		)
		==
		store_2d::dim(
			1U,
			1U
		)
	);
}

FCPPT_CATCH_END
