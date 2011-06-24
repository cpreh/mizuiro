#include <mizuiro/image/views_are_compatible.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/bgra.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/cstdint.hpp>

namespace
{

typedef mizuiro::image::format<
	mizuiro::image::dimension<
		3
	>,
	mizuiro::image::interleaved<
		mizuiro::color::homogenous_static<
			boost::uint8_t,
			mizuiro::color::layout::rgba
		>
	>
> format_3d_rgba8;

typedef mizuiro::image::format<
	mizuiro::image::dimension<
		3
	>,
	mizuiro::image::interleaved<
		mizuiro::color::homogenous_static<
			boost::uint8_t,
			mizuiro::color::layout::bgra
		>
	>
> format_3d_bgra8;

typedef mizuiro::image::format<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::image::interleaved<
		mizuiro::color::homogenous_static<
			boost::uint8_t,
			mizuiro::color::layout::bgra
		>
	>
> format_2d_bgra8;

typedef mizuiro::image::format<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::image::interleaved<
		mizuiro::color::homogenous_static<
			float,
			mizuiro::color::layout::bgra
		>
	>
> format_2d_bgra_f;

typedef mizuiro::image::format<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::image::interleaved<
		mizuiro::color::homogenous_static<
			float,
			mizuiro::color::layout::rgb
		>
	>
> format_2d_rgb8;

}

BOOST_AUTO_TEST_CASE(
	views_are_compatible
)
{
	typedef ::mizuiro::image::view<
		::mizuiro::access::normal,
		::format_3d_bgra8,
		::mizuiro::nonconst_tag
	> view_3d_bgra8;

	typedef ::mizuiro::image::view<
		::mizuiro::access::normal,
		::format_3d_bgra8,
		::mizuiro::nonconst_tag
	> view_3d_rgba8;

	// bgra8 and rgba8 should be compatible to each other
	BOOST_CHECK((
		::mizuiro::image::views_are_compatible<
			view_3d_bgra8,
			view_3d_rgba8
		>::value
	));

	typedef ::mizuiro::image::view<
		::mizuiro::access::normal,
		::format_2d_bgra8,
		::mizuiro::nonconst_tag
	> view_2d_bgra8;

	// 3d bgra8 and 2d bgra8 should not be compatible
	BOOST_CHECK((
		!::mizuiro::image::views_are_compatible<
			view_2d_bgra8,
			view_3d_bgra8
		>::value
	));

	typedef ::mizuiro::image::view<
		::mizuiro::access::normal,
		::format_2d_bgra_f,
		::mizuiro::nonconst_tag
	> view_2d_bgra_f;

	// bgra8 and bgra float should not be compatible
	BOOST_CHECK((
		!::mizuiro::image::views_are_compatible<
			view_2d_bgra8,
			view_2d_bgra_f
		>::value
	));

	typedef ::mizuiro::image::view<
		::mizuiro::access::normal,
		::format_2d_rgb8,
		::mizuiro::nonconst_tag
	> view_2d_rgb8;

	// bgra8 and rgb8 should not be compatible
	BOOST_CHECK((
		!::mizuiro::image::views_are_compatible<
			view_2d_bgra8,
			view_2d_rgb8
		>::value
	));
}
