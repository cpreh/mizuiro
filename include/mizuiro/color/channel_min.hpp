#ifndef MIZUIRO_COLOR_CHANNEL_MIN_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_MIN_HPP_INCLUDED

#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <limits>

namespace mizuiro
{
namespace color
{

template<
	typename T
>
typename boost::enable_if<
	boost::is_integral<
		T
	>,
	T
>::type
channel_min()
{
	return
		std::numeric_limits<
			T
		>::min();
}

template<
	typename T
>
typename boost::enable_if<
	boost::is_floating_point<
		T
	>,
	T
>::type
channel_min()
{
	return
		static_cast<
			T
		>(
			0.
		);
}

}
}

#endif
