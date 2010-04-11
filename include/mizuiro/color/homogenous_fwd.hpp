#ifndef MIZUIRO_COLOR_HOMOGENOUS_FWD_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_FWD_HPP_INCLUDED

#include <mizuiro/color/detail/normal_access.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout,
	typename AccessTypes =
		detail::normal_access<
			ChannelType,
			Layout
		>
>
struct homogenous;

}
}

#endif

