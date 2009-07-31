#include <mizuiro/image/store_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/flipped_view.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/homogenous.hpp>

int main()
{
	typedef float channel_type;

	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous<
				channel_type,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	typedef mizuiro::image::store<
		format
	> store;

	store img(
		store::dim_type(
			4,
			6
		)
	);

	typedef store::view_type view_type;

	view_type const view(
		mizuiro::image::flipped_view(
			img.view()
		)
	);
}
