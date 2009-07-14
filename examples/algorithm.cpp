#include <mizuiro/image/store_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/fill.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/argb.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>

namespace
{

template<
	typename ColorFormat
>
struct d2_format {
	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			2	
		>,
		mizuiro::image::interleaved<
			ColorFormat
		>
	> type;
};

}

int main()
{
	typedef d2_format<
		mizuiro::color::homogenous<
			boost::uint8_t,
			mizuiro::color::layout::rgba
		>
	>::type format1;

	typedef d2_format<
		mizuiro::color::homogenous<
			float,
			mizuiro::color::layout::argb
		>
	>::type format2;

	typedef mizuiro::image::store<
		format1
	> store1;

	typedef mizuiro::image::store<
		format2
	> store2;

	store1::dim_type const dim(
		4,
		2
	);

	store1 img1(
		dim
	);

	mizuiro::image::algorithm::fill(
		img1.view(),
		mizuiro::color::object<
			format1::color_format
		>(
			mizuiro::color::init::red = 42,
			mizuiro::color::init::blue = 150,
			mizuiro::color::init::green = 80,
			mizuiro::color::init::alpha = 255
		)
	);

	std::cout << "before\n";

	mizuiro::image::algorithm::print(
		std::cout,
		img1.view()
	);

	std::cout << "\n\n";

	store2 img2(
		dim
	);

	mizuiro::image::algorithm::copy_and_convert(
		img1.view(),
		img2.view()
	);

	std::cout << "after\n";

	mizuiro::image::algorithm::print(
		std::cout,
		img2.view()
	);

	std::cout << '\n';
}
