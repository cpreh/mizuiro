//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/no_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/r.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/test/external_end.hpp>


namespace
{

typedef
std::uint8_t
channel_type;

typedef
mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::format::homogenous_static<
		channel_type,
		mizuiro::color::layout::r
	>
>
format;

typedef
mizuiro::image::store<
	format
>
store_type;

typedef
mizuiro::image::view<
	store_type::access,
	store_type::format,
	mizuiro::nonconst_tag
>
view_type;

}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	view_operations
)
{
MIZUIRO_DETAIL_POP_WARNING

	store_type store(
		store_type::dim{
			1u,
			1u
		},
		mizuiro::no_init{}
	);

	view_type view(
		store.view()
	);

	view[
		view_type::dim{
			0u,
			0u
		}
	] =
		mizuiro::color::object<
			format::color_format
		>(
			mizuiro::color::init::red() =
				 channel_type{42}
		);

	BOOST_CHECK_EQUAL(
		view[
			view_type::dim(
				0u,
				0u
			)
		].get(
			mizuiro::color::channel::red()
		),
		channel_type{42}
	);

	{
		auto it(
			view.begin()
		);

		BOOST_CHECK_EQUAL(
			(*it).get(
				mizuiro::color::channel::red()
			),
			channel_type{42}
		);

		++it;

		BOOST_CHECK(
			it
			==
			view.end()
		);

		--it;

		BOOST_CHECK(
			it
			==
			view.begin()
		);
	}

	BOOST_CHECK(
		view.begin()
		+
		1
		==
		view.end()
	);

	BOOST_CHECK(
		view.end()
		-
		view.begin()
		==
		1
	);
}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	view_fill
)
{
MIZUIRO_DETAIL_POP_WARNING

	store_type const store(
		store_type::dim{
			1u,
			1u
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
						channel_type{42}
				),
				mizuiro::image::algorithm::uninitialized::yes
			);
		}
	);

	BOOST_CHECK_EQUAL(
		store.view()[
			store_type::dim(
				0u,
				0u
			)
		].get(
			mizuiro::color::channel::red()
		),
		channel_type{42}
	);
}
