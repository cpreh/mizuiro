//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/const_tag.hpp>
#include <mizuiro/default_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/access/advance_pointer.hpp>
#include <mizuiro/image/access/pointer_difference.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <fcppt/catch/begin.hpp>
#include <fcppt/catch/end.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename ImageFormat
>
void
test_format(
	mizuiro::image::types::value_type<
		ImageFormat
	> const _init
)
{
	using
	store_type
	=
	mizuiro::image::store<
		ImageFormat
	>;

	using
	dim
	=
	typename
	store_type::dim;

	store_type const store(
		dim{
			2U,
			2U
		},
		_init
	);

	using
	access
	=
	typename
	store_type::access;

	CHECK(
		mizuiro::image::access::pointer_difference<
			access,
			mizuiro::const_tag,
			ImageFormat
		>(
			store.format_store(),
			mizuiro::image::access::advance_pointer<
				access,
				mizuiro::const_tag,
				ImageFormat
			>(
				store.format_store(),
				store.data(),
				3
			),
			store.data()
		)
		==
		3
	);
}

}

FCPPT_CATCH_BEGIN

TEST_CASE(
	"image interleaved",
	"[mizuiro]"
)
{
	using
	dimension
	=
	mizuiro::image::dimension<
		2
	>;

	using
	color_format
	=
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::rgba
	>;

	test_format<
		mizuiro::image::format::interleaved<
			dimension,
			color_format
		>
	>(
		mizuiro::color::object<
			color_format
		>(
			mizuiro::default_init()
		)
	);
}

FCPPT_CATCH_END
