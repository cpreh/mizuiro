#ifndef MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/channel_proxy_decl.hpp>
#include <mizuiro/detail/copy_n.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/const_raw_pointer.hpp>

template<
	typename Pointer,
	typename ValueType
>
mizuiro::color::channel_proxy<Pointer, ValueType>::channel_proxy(
	pointer const data_
)
:
	data_(data_)
{}

template<
	typename Pointer,
	typename ValueType
>
mizuiro::color::channel_proxy<Pointer, ValueType> &
mizuiro::color::channel_proxy<Pointer, ValueType>::operator=(
	value_type const ref
)
{
	mizuiro::detail::copy_n(
		reinterpret_cast<
			const_raw_pointer
		>(
			&ref
		),
		sizeof(ref),
		data_.get()
	);

	return *this;
}

template<
	typename Pointer,
	typename ValueType
>
mizuiro::color::channel_proxy<Pointer, ValueType>::
operator typename mizuiro::color::channel_proxy<Pointer, ValueType>::value_type() const
{
	value_type ret;

	mizuiro::detail::copy_n(
		data_.get(),
		sizeof(ret),
		reinterpret_cast<
			raw_pointer
		>(
			&ret
		)
	);

	return ret;
}

#endif
