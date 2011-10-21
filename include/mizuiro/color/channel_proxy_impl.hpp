//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/const_raw_pointer.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/color/channel_proxy_decl.hpp>
#include <mizuiro/detail/copy_n.hpp>


template<
	typename Pointer,
	typename ValueType
>
mizuiro::color::channel_proxy<Pointer, ValueType>::channel_proxy(
	pointer const _data
)
:
	data_(_data)
{}

template<
	typename Pointer,
	typename ValueType
>
mizuiro::color::channel_proxy<Pointer, ValueType> &
mizuiro::color::channel_proxy<Pointer, ValueType>::operator=(
	value_type const _ref
)
{
	mizuiro::detail::copy_n(
		reinterpret_cast<
			const_raw_pointer
		>(
			&_ref
		),
		sizeof(_ref),
		data_
	);

	return *this;
}

template<
	typename Pointer,
	typename ValueType
>
typename mizuiro::color::channel_proxy<Pointer, ValueType>::value_type
mizuiro::color::channel_proxy<Pointer, ValueType>::get() const
{
	value_type ret;

	mizuiro::detail::copy_n(
		data_,
		sizeof(ret),
		reinterpret_cast<
			raw_pointer
		>(
			&ret
		)
	);

	return ret;
}

template<
	typename Pointer,
	typename ValueType
>
mizuiro::color::channel_proxy<Pointer, ValueType>::
operator typename mizuiro::color::channel_proxy<Pointer, ValueType>::value_type() const
{
	return get();
}

#endif
