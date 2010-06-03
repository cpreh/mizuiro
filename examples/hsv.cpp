#include <mizuiro/color/layout/hsva.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <boost/cstdint.hpp>

int main()
{
	typedef mizuiro::color::homogenous<
		boost::uint8_t,
		mizuiro::color::layout::hsva
	> hsva_format;

	typedef mizuiro::color::object<
		hsva_format
	> hsva_object;

	hsva_object const source(
		mizuiro::color::init::hue %= 0.5,
		mizuiro::color::init::saturation %= 1.0,
		mizuiro::color::init::value %= 0.7,
		mizuiro::color::init::alpha %= 1.0
	);
}
