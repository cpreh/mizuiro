//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <mizuiro/no_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/r.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace
{

using
channel_type
=
std::uint8_t;

using
format
=
mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::format::homogenous_static<
		channel_type,
		mizuiro::color::layout::r
	>
>;

using
store_type
=
mizuiro::image::store<
	format
>;

using
view_type
=
mizuiro::image::view<
	store_type::access,
	store_type::format,
	mizuiro::nonconst_tag
>;

}

FCPPT_CATCH_BEGIN

TEST_CASE(
	"view operations",
	"[mizuiro]"
)
{
	store_type store(
		store_type::dim{
			1U,
			1U
		},
		mizuiro::no_init{}
	);

	view_type view(
		store.view()
	);

	view[
		view_type::dim{
			0U,
			0U
		}
	] =
		mizuiro::color::object<
			format::color_format
		>(
			mizuiro::color::init::red() =
				 channel_type{42} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		);

	CHECK(
		view[
			view_type::dim(
				0U,
				0U
			)
		].get(
			mizuiro::color::channel::red()
		)
		==
		channel_type{42} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	{
		auto it(
			view.begin()
		);

		CHECK(
			(*it).get(
				mizuiro::color::channel::red()
			)
			==
			channel_type{42}
		);

		++it;

		CHECK(
			it
			==
			view.end()
		);

		--it;

		CHECK(
			it
			==
			view.begin()
		);
	}

	CHECK(
		view.begin()
		+
		1
		==
		view.end()
	);

	CHECK(
		view.end()
		-
		view.begin()
		==
		1
	);
}

TEST_CASE(
	"view fill",
	"[mizuiro]"
)
{
	store_type const store(
		store_type::dim{
			1U,
			1U
		},
		[](
			store_type::view_type const &_view
		)
		{
			mizuiro::image::algorithm::fill_c(
				view_type(
					_view
				),
				mizuiro::color::object<
					format::color_format
				>(
					mizuiro::color::init::red() =
						channel_type{42} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				),
				mizuiro::image::algorithm::uninitialized::yes
			);
		}
	);

	CHECK(
		store.view()[
			store_type::dim(
				0U,
				0U
			)
		].get(
			mizuiro::color::channel::red()
		)
		==
		channel_type{42} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}

FCPPT_CATCH_END
