//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/const_tag.hpp>
#include <mizuiro/default_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/access/advance_pointer.hpp>
#include <mizuiro/image/access/pointer_difference.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <mizuiro/test/external_end.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/detail/external_end.hpp>


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
	typedef
	mizuiro::image::store<
		ImageFormat
	>
	store_type;

	typedef
	typename
	store_type::dim
	dim;

	store_type const store(
		dim{
			2u,
			2u
		},
		_init
	);

	typedef
	typename
	store_type::access
	access;

	BOOST_CHECK((
		mizuiro::image::access::pointer_difference<
			access,
			mizuiro::const_tag
		>(
			store.format_store(),
			mizuiro::image::access::advance_pointer<
				access,
				mizuiro::const_tag
			>(
				store.format_store(),
				store.data(),
				3
			),
			store.data()
		)
		==
		3
	));
}

}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	interleaved
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef
	mizuiro::image::dimension<
		2
	>
	dimension;

	typedef
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::rgba
	>
	color_format;

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
