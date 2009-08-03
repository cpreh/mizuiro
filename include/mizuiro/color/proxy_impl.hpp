#ifndef MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/proxy_decl.hpp>
#include <mizuiro/color/detail/copy_channel.hpp>
#include <mizuiro/detail/nonconst_tag.hpp>
#include <mizuiro/detail/const_tag.hpp>
#include <boost/mpl/for_each.hpp>

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
	typename Other
>
mizuiro::color::proxy<Layout, Constness> const &
mizuiro::color::proxy<Layout, Constness>::operator=(
	Other const &other
) const
{
	boost::mpl::for_each<
		typename layout::layout::order
	>(
		detail::copy_channel<
			proxy<
				Layout,
				Constness
			>,
			Other
		>(
			*this,
			other
		)
	);

	return *this;
}

template<
	typename Layout,
	typename Constness
>
template<
	typename Channel
>
void
mizuiro::color::proxy<Layout, Constness>::set(
	typename layout::template channel_value_type<
		Channel
	>::type const &ref
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
