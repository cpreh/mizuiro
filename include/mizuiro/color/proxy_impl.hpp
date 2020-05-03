//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/proxy_decl.hpp>
#include <mizuiro/color/access/extract_channel.hpp>
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
mizuiro::color::proxy<
	Access,
	Format,
	Constness
>::proxy(
	proxy &&
)
noexcept
= default;

// NOLINTNEXTLINE(cppcoreguidelines-c-copy-assignment-signature,misc-unconventional-assign-operator)
template<
	typename Access,
	typename Format,
	typename Constness
>
template<
	typename Other
>
// NOLINTNEXTLINE(cppcoreguidelines-c-copy-assignment-signature,misc-unconventional-assign-operator)
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
		[
			this,
			&_other
		](
			auto const &_channel_inner
		)
		{
			this->set(
				_channel_inner,
				_other.get(
					_channel_inner
				)
			);
		}
	);

	return
		*this;
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
>::~proxy()
= default;

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
		mizuiro::nonconst_tag,
		Format
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
			mizuiro::const_tag,
			Format
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
>::format_store_type
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
