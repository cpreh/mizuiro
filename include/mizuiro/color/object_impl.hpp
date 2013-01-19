//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/color/format_base_impl.hpp>
#include <mizuiro/color/format_store_impl.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_decl.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/init/detail/assign_object.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


template<
	typename Format
>
mizuiro::color::object<
	Format
>::object(
	format_store_type const &_format
)
:
	base(
		_format
	),
	data_()
{
}

template<
	typename Format
>
mizuiro::color::object<
	Format
>::object(
	object const &_other
)
:
	base(
		_other.format_store()
	),
	data_(
		_other.data_
	)

{
}

template<
	typename Format
>
template<
	typename Other
>
mizuiro::color::object<
	Format
>::object(
	Other const &_other,
	typename boost::enable_if<
		mizuiro::color::is_color<
			Other
		>
	>::type *
)
:
	base(
		_other.format_store()
	),
	data_()
{
	proxy(
		data_.data(),
		this->format_store()
	) = _other;
}

template<
	typename Format
>
template<
	typename Vector
>
mizuiro::color::object<
	Format
>::object(
	mizuiro::color::init::detail::values<
		Vector
	> const &_init,
	format_store_type const &_format
)
:
	base(
		_format
	),
	data_()
{
	mizuiro::color::init::detail::assign_object(
		*this,
		_init
	);
}

template<
	typename Format
>
template<
	typename Channel
>
void
mizuiro::color::object<
	Format
>::set(
	Channel const &_channel,
	typename mizuiro::color::types::channel_value<
		format,
		Channel
	>::type const &_ref
)
{
	this->make_proxy().set(
		_channel,
		_ref
	);
}

template<
	typename Format
>
template<
	typename Channel
>
typename mizuiro::color::types::channel_reference<
	typename mizuiro::color::object<
		Format
	>::access,
	typename mizuiro::color::object<
		Format
	>::format,
	Channel,
	mizuiro::const_tag
>::type
mizuiro::color::object<
	Format
>::get(
	Channel const &_channel
) const
{
	return
		this->make_const_proxy().get(
			_channel
		);
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::pointer
mizuiro::color::object<
	Format
>::data()
{
	return
		this->make_proxy().data();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_pointer
mizuiro::color::object<
	Format
>::data() const
{
	return
		this->make_const_proxy().data();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::pointer
mizuiro::color::object<
	Format
>::data_end()
{
	return
		this->make_proxy().data_end();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_pointer
mizuiro::color::object<
	Format
>::data_end() const
{
	return
		this->make_const_proxy().data_end();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::format_store_type const
mizuiro::color::object<
	Format
>::format_store() const
{
	return
		this->format_store_base();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::proxy const
mizuiro::color::object<
	Format
>::make_proxy()
{
	return
		proxy(
			data_.data(),
			this->format_store()
		);
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_proxy const
mizuiro::color::object<
	Format
>::make_const_proxy() const
{
	return
		const_proxy(
			data_.data(),
			this->format_store()
		);
}

#endif
