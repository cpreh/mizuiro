#ifndef MIZUIRO_IMAGE_STRIDE_POINTER_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STRIDE_POINTER_IMPL_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_decl.hpp>

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::image::detail::stride_pointer<T, Stride>::stride_pointer(
	T const base_
)
:
	base_(base_)
{}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::image::detail::stride_pointer<T, Stride> &
mizuiro::image::detail::stride_pointer<T, Stride>::operator+=(
	difference_type const diff
)
{
	base_ += sstride * diff;
	return *this;
}

template<
	typename T,
	mizuiro::size_type Stride
>

mizuiro::image::detail::stride_pointer<T, Stride> &
mizuiro::image::detail::stride_pointer<T, Stride>::operator-=(
	difference_type const diff
)
{
	base_ -= sstride * diff;
	return *this;
}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::image::detail::stride_pointer<T, Stride> &
mizuiro::image::detail::stride_pointer<T, Stride>::operator++()
{
	base_ += sstride;
	return *this;
}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::image::detail::stride_pointer<T, Stride> &
mizuiro::image::detail::stride_pointer<T, Stride>::operator--()
{
	base_ -= sstride;
	return *this;
}

#endif
