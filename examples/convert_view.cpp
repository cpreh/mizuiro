#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/store_impl.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/alpha.hpp>
#include <fcppt/tr1/array.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>

namespace
{

template<
	typename Format
>
struct make_2d_format
{
	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::image::interleaved<
			Format
		>
	> type;
};

}

int main()
{
	typedef boost::uint8_t base_type;

	typedef make_2d_format<
		mizuiro::color::homogenous<
			base_type,
			mizuiro::color::layout::rgba
		>
	>::type rgba_format;

	typedef make_2d_format<
		mizuiro::color::homogenous<
			base_type,
			mizuiro::color::layout::alpha
		>
	>::type alpha_format;

	typedef make_2d_format<
		mizuiro::color::homogenous<
			base_type,
			mizuiro::color::layout::rgba
		>
	>::type rgba_format;
	
	mizuiro::size_type const
		width(
			3
		),
		height(
			12
		);

	typedef std::tr1::array<
		unsigned char,
		width
		* height
		* sizeof(base_type)
		* alpha_format::color_format::element_count
	> raw_array;

	raw_array const data = {{
		152, 34, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		232, 52, 0,
		229, 59, 0,
		151, 228, 15,
		0, 39, 4
	}};

	typedef mizuiro::image::store<
		rgba_format
	> rgba_store;

	rgba_store::dim_type const dim(
		width,
		height
	);

	rgba_store store(
		dim
	);

	mizuiro::image::algorithm::copy_and_convert(
		mizuiro::image::make_raw_view<
			alpha_format
		>(
			data.data(),
			dim,
			rgba_store::view_type::pitch_type::null()
		),
		store.view()
	);

	mizuiro::image::algorithm::print(
		std::cout,
		store.view()
	);

	std::cout<< '\n';
}
