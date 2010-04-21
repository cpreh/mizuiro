#ifndef MIZUIRO_COLOR_ACCESS_CHANNEL_MAX_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_CHANNEL_MAX_HPP_INCLUDED

#include <mizuiro/color/detail/channel_max.hpp>
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
channel_max()
{
	return
		color::detail::channel_max<
			typename color::types<
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
