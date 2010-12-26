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
template<typename Float>
typename
boost::enable_if_c
<
	boost::is_floating_point<Float>::value,
	Float
>::type
luminance(
	Float const r,
	Float const g,
	Float const b)
{
	// For an explanation of the magic numbers here, see:
	// http://en.wikipedia.org/wiki/Yuv
	return static_cast<Float>(0.299)*r + static_cast<Float>(0.587)*g + static_cast<Float>(0.114)*b;
}
}
}

#endif
