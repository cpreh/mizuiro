//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/bgra.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/linear_view_impl.hpp>
#include <mizuiro/image/algorithm/can_copy.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/detail/external_end.hpp>


namespace
{

typedef mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		3
	>,
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::rgba
	>
> format_3d_rgba8;

typedef mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		3
	>,
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::bgra
	>
> format_3d_bgra8;

typedef mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::bgra
	>
> format_2d_bgra8;

typedef mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::format::homogenous_static<
		float,
		mizuiro::color::layout::bgra
	>
> format_2d_bgra_f;

typedef mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::format::homogenous_static<
		float,
		mizuiro::color::layout::rgb
	>
> format_2d_rgb8;

}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	can_copy
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef ::mizuiro::image::linear_view<
		::mizuiro::access::normal,
		::format_3d_bgra8,
		::mizuiro::nonconst_tag
	> view_3d_bgra8;

	typedef ::mizuiro::image::linear_view<
		::mizuiro::access::normal,
		::format_3d_rgba8,
		::mizuiro::nonconst_tag
	> view_3d_rgba8;

	// bgra8 and rgba8 should be compatible to each other
	BOOST_CHECK((
		::mizuiro::image::algorithm::can_copy<
			view_3d_bgra8,
			view_3d_rgba8
		>::value
	));

	typedef ::mizuiro::image::linear_view<
		::mizuiro::access::normal,
		::format_2d_bgra8,
		::mizuiro::nonconst_tag
	> view_2d_bgra8;

	typedef ::mizuiro::image::linear_view<
		::mizuiro::access::normal,
		::format_2d_bgra_f,
		::mizuiro::nonconst_tag
	> view_2d_bgra_f;

	// bgra8 and bgra float should not be compatible
	BOOST_CHECK((
		!::mizuiro::image::algorithm::can_copy<
			view_2d_bgra8,
			view_2d_bgra_f
		>::value
	));

	typedef ::mizuiro::image::linear_view<
		::mizuiro::access::normal,
		::format_2d_rgb8,
		::mizuiro::nonconst_tag
	> view_2d_rgb8;

	// bgra8 and rgb8 should not be compatible
	BOOST_CHECK((
		!::mizuiro::image::algorithm::can_copy<
			view_2d_bgra8,
			view_2d_rgb8
		>::value
	));
}
