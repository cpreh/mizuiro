//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/proxy_decl.hpp>
#include <mizuiro/color/detail/copy_channel.hpp>
#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <boost/mpl/for_each.hpp>

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::color::proxy<Access, Format, Constness>::proxy(
	pointer const data_
)
:
	data_(data_)
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename OtherConstness
>
mizuiro::color::proxy<Access, Format, Constness>::proxy(
	color::proxy<
		Access,
		Format,
		OtherConstness
	> const &other_
)
:
	data_(other_.data())
{}

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename Other
>
mizuiro::color::proxy<Access, Format, Constness> const &
mizuiro::color::proxy<Access, Format, Constness>::operator=(
	Other const &other
) const
{
	boost::mpl::for_each<
		typename Format::layout::order
	>(
		detail::copy_channel<
			proxy<
				Access,
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
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename Channel
>
void
mizuiro::color::proxy<Access, Format, Constness>::set(
	typename types::channel_value<
		Format,
		Channel
	>::type const &ref
) const
{
	extract_channel(
		Access(),
		Format(),
		Channel(),
		mizuiro::nonconst_tag(),
		data_	
	) = ref;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename Channel
>
typename mizuiro::color::types::channel_reference<
	Access,
	Format,
	Channel,
	mizuiro::const_tag
>::type
mizuiro::color::proxy<Access, Format, Constness>::get() const
{
	return
		extract_channel(
			Access(),
			Format(),
			Channel(),
			mizuiro::const_tag(),
			data_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename mizuiro::color::proxy<Access, Format, Constness>::pointer
mizuiro::color::proxy<Access, Format, Constness>::data() const
{
	return data_;
}

#endif
