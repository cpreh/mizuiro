#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/output.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>

int main()
{
	typedef boost::uint8_t channel;

	typedef mizuiro::color::object<
		mizuiro::color::homogenous<
			channel,
			mizuiro::color::layout::rgba
		>
	> rgba_color;

	rgba_color const testcolor(
		mizuiro::color::init::red = static_cast<channel>(42),
		mizuiro::color::init::green = static_cast<channel>(5),
		mizuiro::color::init::blue = static_cast<channel>(100),
		mizuiro::color::init::alpha = static_cast<channel>(53)
	);

	rgba_color const testcolor2(
		mizuiro::color::init::red %= 0.5,
		mizuiro::color::init::blue %= 0.3,
		mizuiro::color::init::green %= 0.1,
		mizuiro::color::init::alpha %= 1.0
	);

	std::cout
		<< testcolor
		<< ' '
		<< testcolor2
		<< '\n';
}
