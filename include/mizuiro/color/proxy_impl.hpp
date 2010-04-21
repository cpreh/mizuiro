#ifndef MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/proxy_decl.hpp>
#include <mizuiro/color/detail/copy_channel.hpp>
#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <boost/mpl/for_each.hpp>

template<
	typename Format,
	typename Constness
>
mizuiro::color::proxy<Format, Constness>::proxy(
	pointer const data_
)
:
	data_(data_)
{}

template<
	typename Format,
	typename Constness
>
template<
	typename Other
>
mizuiro::color::proxy<Format, Constness> const &
mizuiro::color::proxy<Format, Constness>::operator=(
	Other const &other
) const
{
	boost::mpl::for_each<
		typename Format::layout::order
	>(
		detail::copy_channel<
			proxy<
				Format,
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
	typename Format,
	typename Constness
>
template<
	typename Channel
>
void
mizuiro::color::proxy<Format, Constness>::set(
	typename Access::template channel_value_type<
		Channel
	>::type const &ref
) const
{
	extract_channel<
		Access,
		Format,
		Channel,
		mizuiro::nonconst_tag
	>(
		data_	
	) = ref;
}

template<
	typename Format,
	typename Constness
>
template<
	typename Channel
>
typename Format:: template channel_reference<
	Channel,
	mizuiro::const_tag
>::type
mizuiro::color::proxy<Format, Constness>::get() const
{
	return
		color::access::extract_channel<
			Access,
			Format,
			Channel,
			mizuiro::const_tag
		>(
			data_
		);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::color::proxy<Format, Constness>::pointer
mizuiro::color::proxy<Format, Constness>::data() const
{
	return data_;
}

#endif
