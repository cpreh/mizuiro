#ifndef MIZUIRO_COLOR_LUMINANCE_HPP_INCLUDED
#define MIZUIRO_COLOR_LUMINANCE_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace mizuiro
{
namespace color
{

// This calculates the luminance of three rgb values. This is
// intentionally a function operating on floats because
//
// a) the calculation needs floating point arithmetic.
// b) the calculation usually takes place in convert:: where we use floats, anyway
template<
	typename Float
>
typename boost::enable_if
<
	boost::is_floating_point<
		Float
	>,
	Float
>::type
luminance(
	Float const _red,
	Float const _green,
	Float const _blue
)
{
	// For an explanation of the magic numbers here, see:
	// http://en.wikipedia.org/wiki/Yuv
	return
		static_cast<
			Float
		>(
			0.299
		)
		* _red
		+
		static_cast<
			Float
		>(
			0.587
		)
		* _green
		+
		static_cast<
			Float
		>(
			0.114
		)
		* _blue;
}

}
}

#endif
