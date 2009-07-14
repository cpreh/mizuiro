#include <mizuiro/image/store_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/bound_impl.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <boost/cstdint.hpp>

int main()
{
	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			3
		>,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous<
				boost::uint8_t,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	typedef mizuiro::image::store<
		format
	> store;

	store img(
		store::dim_type(
			3,
			2,
			1	
		)
	);

	typedef store::view_type view_type;

	typedef view_type::bound_type bound_type;

	view_type const sub_view(
		mizuiro::image::sub_view(
			img.view(),
			bound_type(
				bound_type::dim_type(
					0,
					0,
					0
				),
				bound_type::dim_type(
					1,
					1,
					1
				)
			)
		)
	);
}
