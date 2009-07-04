#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/raw_pointer.hpp>
#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/tr1/array.hpp>
#include <boost/cstdint.hpp>

int main()
{
	typedef mizuiro::image::dimension<
		2
	> dim_type;

	typedef mizuiro::image::format<
		dim_type,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous<
				boost::uint8_t,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	mizuiro::size_type const
		width(
			20
		),
		height(
			30
		);

	typedef std::tr1::array<
		unsigned char,
		width * height
	> raw_array;

	raw_array raw_data = {{ 0 }};

	typedef mizuiro::image::raw_view<
		format,
		mizuiro::image::raw_pointer
	>::type view_type;

	view_type const view(
		mizuiro::image::make_raw_view<
			format
		>(
			raw_data.data(),
			dim_type(
				width,
				height
			),
			view_type::pitch_type::null()
		)
	);

	(*view.begin()).get<
		mizuiro::color::channel::red
	>();
}
