#ifndef MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/channel_proxy_decl.hpp>
#include <sge/algorithm/copy_n.hpp> // TODO

template<
	typename Layout,
	typename Channel,
	typename Constness
>
mizuiro::color::channel_proxy<Layout, Channel, Constness>::channel_proxy(
	pointer const data_
)
:
	data_(data_)
{}

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
	sge::algorithm::copy_n(
		reinterpret_cast<
			unsigned char const * // TODO
		>(
			&ref
		),
		sizeof(ref),
		data_.get()
	);

	return *this;
}

template<
	typename Layout,
	typename Channel,
	typename Constness
>
mizuiro::color::channel_proxy<Layout, Channel, Constness>::
operator typename mizuiro::color::channel_proxy<Layout, Channel, Constness>::value_type() const
{
	value_type ret;

	sge::algorithm::copy_n(
		data_.get(),
		sizeof(ret),
		reinterpret_cast<
			unsigned char * //typename pointer::value_type *
		>(
			&ret
		)
	);

	return ret;
}

#endif
