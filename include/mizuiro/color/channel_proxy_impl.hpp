#ifndef MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/channel_proxy_decl.hpp>

template<
	typename Layout,
	typename Channel,
	typename Constness
>
mizuiro::color::channel_proxy<Layout, Channel, Constness> &
mizuiro::color::channel_proxy<Layout, Channel, Constness>::operator=(
	typename layout:: template channel_value_type<
		channel
	>::type ref
)
{
}

template<
	typename Layout,
	typename Channel,
	typename Constness
>
mizuiro::color::channel_proxy<Layout, Channel, Constness>::
operator typename layout:: template channel_value_type<
	channel
>::type () const
{

}

#endif
