#ifndef MIZUIRO_COLOR_ACCESS_CHANNEL_MIN_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_CHANNEL_MIN_HPP_INCLUDED

#include <mizuiro/color/detail/channel_min.hpp>
#include <mizuiro/color/types/channel_value.hpp>

namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Channel
>
typename color::types::channel_value<
	Access,
	Format,
	Channel
>::type
channel_min()
{
	return
		color::detail::channel_min<
			typename color::types::channel_value<
				Access,
				Format,
				Channel
			>::type
		>();
}

}
}
}

#endif
