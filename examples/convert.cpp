#include <mizuiro/color/object.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/layout/alpha.hpp>
#include <mizuiro/color/convert.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/homogenous.hpp>
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

	typedef mizuiro::color::object<
		mizuiro::color::homogenous<
			boost::uint8_t,
			mizuiro::color::layout::alpha
		>
	> alpha_color;

	gray_color test_gray(
		(mizuiro::color::init::gray = static_cast<boost::uint8_t>(42))
	);

	rgba_color const test_rgb(
		mizuiro::color::convert<
			rgba_color::format
		>(
			test_gray
		)
	);

	std::cout 
		<< "gray value was: " 
		<< test_gray 
		<< " and was converted to" 
		<< test_rgb
		<< '\n';
	
	typedef 
		mizuiro::color::object
		<
			mizuiro::color::homogenous
			<
				float,
				mizuiro::color::layout::rgba
			>
		> rgba_float_color;

	rgba_float_color test_float
	(
		mizuiro::color::convert
		<
			rgba_float_color::format
		>
		(
			test_rgb
		)
	);
	
	std::cout 
		<< "converted the rgb value to floats: "
		<< test_float
		<< '\n';
	
	gray_color test_gray2(
		mizuiro::color::convert<
			gray_color::format
		>
		(
			test_float
		)
	);

	std::cout 
		<< "converted back to gray: "
		<< test_gray2
		<< '\n';
	
	alpha_color const test_alpha(
		mizuiro::color::init::alpha %= 0.5
	);

	std::cout
		<< "alpha converted to rgba: "
		<< mizuiro::color::convert<
			rgba_float_color::format
		>(
			test_alpha
		)
		<< '\n';
}
