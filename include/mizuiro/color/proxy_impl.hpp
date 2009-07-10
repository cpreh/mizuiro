#ifndef MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/proxy_decl.hpp>

template<
	typename Layout,
	typename Constness
>
mizuiro::color::proxy<Layout, Constness>::proxy(
	pointer const data_
)
:
	data_(data_)
{}

template<
	typename Layout,
	typename Constness
>
template<
	typename Channel
>
void
mizuiro::color::proxy<Layout, Constness>::set(
	typename layout:: template channel_reference<
		Channel,
		mizuiro::detail::const_tag
	>::type ref
) const
{
	layout:: template extract_channel<
		Channel,
		mizuiro::detail::nonconst_tag
	>::execute(
		data_	
	) = ref;
}

template<
	typename Layout,
	typename Constness
>
template<
	typename Channel
>
typename Layout:: template channel_reference<
	Channel,
	mizuiro::detail::const_tag
>::type
mizuiro::color::proxy<Layout, Constness>::get() const
{
	return layout:: template extract_channel<
		Channel,
		mizuiro::detail::const_tag
	>::execute(
		data_
	);
}

#endif
