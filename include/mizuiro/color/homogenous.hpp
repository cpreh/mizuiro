#ifndef MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/detail/homogenous_layout.hpp>

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
		detail::homogenous_layout<
			channel_type &,
			pointer,
			layout
		>
	> reference;

	typedef proxy<
		detail::homogenous_layout<
			channel_type const &,
			const_pointer,
			layout
		>
	> const_reference;
};

}
}

#endif
