#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/output.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>

int main()
{
	typedef mizuiro::color::object<
		mizuiro::color::homogenous<
			boost::uint8_t,
			mizuiro::color::layout::rgba
		>
	> rgba_color;

	typedef mizuiro::color::object<
		mizuiro::color::homogenous<
			boost::uint8_t,
			mizuiro::color::layout::gray
		>
	> gray_color;

	gray_color test1(
		(mizuiro::color::init::gray = 42)
	);

	rgba_color const test2(
		mizuiro::color::convert<
			rgba_color
		>(
			test1
		)
	);

	std::cout << test2 << '\n';
}
