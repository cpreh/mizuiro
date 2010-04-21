#ifndef MIZUIRO_COLOR_ACCESS_CHANNEL_MIN_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_CHANNEL_MIN_HPP_INCLUDED

#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Channel
>
typename channel_value_type<Channel>::type
channel_min()
{
	return
		detail::channel_min<
			typename types::channel_value_type<
				Channel
			>::type
		>::get();
}

}
}
}

#endif
