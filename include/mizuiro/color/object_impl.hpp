//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/color/init/detail/assign_object.hpp>
#include <mizuiro/color/object_decl.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/access/homogenous_normal.hpp>
#include <boost/utility/enable_if.hpp>

template<
	typename Format
>
mizuiro::color::object<Format>::object(
	Format const &_format
)
:
	data_(),
	format_(&_format)
{}

template<
	typename Format
>
mizuiro::color::object<Format>::object(
	object const &_other
)
:
	data_(_other.data_),
	format_(_other.format_)

{}

template<
	typename Format
>
template<
	typename Other
>
mizuiro::color::object<Format>::object(
	Other const &_other,
	typename boost::enable_if<
		color::is_color<
			Other
		>
	>::type *
)
:
	data_(),
	format_(
		_other.format()
	)
{
	proxy(
		data_.data(),
		*format_
	) = _other;
}

template<
	typename Format
>
template<
	typename Init
>
mizuiro::color::object<Format>::object(
	Init const &_init,
	Format const &_format,
	typename boost::disable_if<
		color::is_color<
			Init
		>
	>::type *
)
:
	data_(),
	format_(&_format)
{
	init::detail::assign_object(
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
mizuiro::color::object<Format>::set(
	Channel const &_channel,
	typename types::channel_value<
		format,
		Channel
	>::type const &_ref
)
{
	proxy(
		data_.data(),
		*format_
	)
	.set(
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
mizuiro::color::object<Format>::get(
	Channel const &_channel
) const
{
	return
		const_proxy(
			data_.data(),
			*format_
		).get(
			_channel
		);
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::pointer
mizuiro::color::object<Format>::data()
{
	return data_.data();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_pointer
mizuiro::color::object<Format>::data() const
{
	return data_.data();
}

#endif
