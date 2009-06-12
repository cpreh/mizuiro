#ifndef MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout
>
struct homogenous {
	typedef ChannelType channel_type;
	typedef channel_type value_type;
	typedef value_type *pointer;
	typedef value_type const *const_pointer;
	typedef Layout layout;

	typedef proxy<
		layout
	> reference;
};

}
}

#endif
