//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/difference_type.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/proxy_decl.hpp>
#include <mizuiro/color/access/advance_pointer.hpp>
#include <mizuiro/color/access/extract_channel.hpp>
#include <mizuiro/color/access/stride.hpp>
#include <mizuiro/color/detail/copy_channel.hpp>
#include <mizuiro/color/format/base_impl.hpp>
#include <mizuiro/color/format/compatible.hpp>
#include <mizuiro/color/format/store_impl.hpp>


template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::proxy(
	pointer const _data,
	format_store_type const &_format
)
:
	base(
		_format
	),
	data_(
		_data
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename OtherConstness
>
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::proxy(
	mizuiro::color::proxy<
		Access,
		Format,
		OtherConstness
	> const &_other
)
:
	base(
		_other.format_store()
	),
	data_(
		_other.data()
	)
{
}

template<
	typename Access,
	typename Format,
	typename Constness
>
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::proxy(
	proxy const &
) = default;

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename Other
>
mizuiro::color::proxy<
	Access,
	Format,
	Constness
> const &
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::operator=(
	Other const &_other
) const
{
	static_assert(
		mizuiro::color::format::compatible<
			Format,
			typename
			Other::format
		>::value,
		"Formats must be compatible in proxy assignment"
	);

	mizuiro::color::for_each_channel(
		*this,
		mizuiro::color::detail::copy_channel<
			mizuiro::color::proxy<
				Access,
				Format,
				Constness
			>,
			Other
		>(
			*this,
			_other
		)
	);

	return
		*this;
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
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::set(
	Channel const &_channel,
	mizuiro::color::types::channel_value<
		Format,
		Channel
	> const &_ref
) const
{
	mizuiro::color::access::extract_channel<
		Access,
		mizuiro::nonconst_tag
	>(
		this->format_store(),
		_channel,
		data_
	) =
		_ref;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename Channel
>
mizuiro::color::types::channel_reference<
	Access,
	Format,
	Channel,
	mizuiro::const_tag
>
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::get(
	Channel const &_channel
) const
{
	return
		mizuiro::color::access::extract_channel<
			Access,
			mizuiro::const_tag
		>(
			this->format_store(),
			_channel,
			data_
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::pointer
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::data() const
{
	return
		data_;
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::pointer
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::data_end() const
{
	return
		mizuiro::color::access::advance_pointer<
			Access,
			Constness
		>(
			this->format_store(),
			this->data(),
			static_cast<
				mizuiro::difference_type
			>(
				mizuiro::color::access::stride<
					Access
				>(
					this->format_store()
				)
			)
		);
}

template<
	typename Access,
	typename Format,
	typename Constness
>
typename
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::format_store_type const
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::format_store() const
{
	return
		this->format_store_base();
}

#endif
