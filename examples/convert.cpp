#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/convert.hpp>
#include <boost/cstdint.hpp>

int main()
{
	typedef mizuiro::color::homogenous<
		boost::uint8_t,
		mizuiro::color::layout::rgba
	> rgba_format;

	typedef mizuiro::color::object<
		rgba_format
	> rgba_color;

	typedef mizuiro::color::homogenous<
		boost::uint8_t,
		mizuiro::color::layout::gray
	> gray_format;

	typedef mizuiro::color::object<
		gray_format
	> gray_color;

	gray_color test1;

	rgba_color test2(
		mizuiro::color::convert<
			rgba_color
		>(
			test1
		)
	);
}
