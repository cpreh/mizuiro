#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/color/channel.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <boost/cstdint.hpp>

int main()
{
	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			3
		>,
		mizuiro::image::interleaved<
			mizurio::color::format<
				mizuiro::color::channel<
					boost::uint8_t
				>,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	typedef mizuiro::image::store<
		format
	> store;

	store img(
		store::dim_type(
			129,
			64,
			32
		)
	);

	typedef store::view_type view_type;

	view_type const view(
		img.view()
	);
}
