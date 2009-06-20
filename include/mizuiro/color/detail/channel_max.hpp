#ifndef MIZUIRO_COLOR_DETAIL_CHANNEL_MAX_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_CHANNEL_MAX_HPP_INCLUDED

#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <limits>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename T,
	typename Enable = void
>
struct channel_max;

template<
	typename T
>
struct channel_max<
	T,
	typename boost::enable_if<
		boost::is_integral<
			T
		>
	>::type
>
{
	static T
	get()
	{
		return std::numeric_limits<
			T
		>::max();
	}
};

template<
	typename T
>
struct channel_max<
	T,
	typename boost::enable_if<
		boost::is_floating_point<
			T
		>
	>::type
>
{
	static T
	get()
	{
		return static_cast<
			T
		>(
			1.0
		);
	}
};

}
}
}

#endif
