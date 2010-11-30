//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_STRIDE_POINTER_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_STRIDE_POINTER_IMPL_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_decl.hpp>
#include <cassert>

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::image::detail::stride_pointer<T, Stride>::stride_pointer(
	T const _base
)
:
	base_(_base)
{}

template<
	typename T,
	mizuiro::size_type Stride
>
template<
	typename OtherT
>
mizuiro::image::detail::stride_pointer<T, Stride>::stride_pointer(
	stride_pointer<
		OtherT,
		Stride
	> const &_other
)
:
	base_(_other.get())
{}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::image::detail::stride_pointer<T, Stride> &
mizuiro::image::detail::stride_pointer<T, Stride>::operator+=(
	difference_type const _diff
)
{
	base_ += sstride * _diff;
	return *this;
}

template<
	typename T,
	mizuiro::size_type Stride
>

mizuiro::image::detail::stride_pointer<T, Stride> &
mizuiro::image::detail::stride_pointer<T, Stride>::operator-=(
	difference_type const _diff
)
{
	base_ -= sstride * _diff;
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

template<
	typename T,
	mizuiro::size_type Stride
>
typename mizuiro::image::detail::stride_pointer<T, Stride>::reference
mizuiro::image::detail::stride_pointer<T, Stride>::operator*() const
{
	return *base_;
}

template<
	typename T,
	mizuiro::size_type Stride
>
typename mizuiro::image::detail::stride_pointer<T, Stride>::reference
mizuiro::image::detail::stride_pointer<T, Stride>::operator[](
	size_type const _index
) const
{
	return *(*this + _index);
}

template<
	typename T,
	mizuiro::size_type Stride
>
typename mizuiro::image::detail::stride_pointer<T, Stride>::difference_type
mizuiro::image::detail::stride_pointer<T, Stride>::operator-(
	stride_pointer const &_other
) const
{
	assert(
		(base_ - _other.base_) % sstride == 0
	);

	return (base_ - _other.base_) / sstride;
}

template<
	typename T,
	mizuiro::size_type Stride
>
bool
mizuiro::image::detail::stride_pointer<T, Stride>::operator==(
	stride_pointer const &_other
) const
{
	return base_ == _other.base_;
}

template<
	typename T,
	mizuiro::size_type Stride
>
T
mizuiro::image::detail::stride_pointer<T, Stride>::get() const
{
	return base_;
}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::image::detail::stride_pointer<T, Stride> const
mizuiro::image::detail::operator +(
	stride_pointer<T, Stride> _pointer,
	typename stride_pointer<T, Stride>::difference_type const _diff
)
{
	return _pointer += _diff;
}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::image::detail::stride_pointer<T, Stride> const
mizuiro::image::detail::operator -(
	stride_pointer<T, Stride> _pointer,
	typename stride_pointer<T, Stride>::difference_type const _diff
)
{
	return _pointer -= _diff;
}

template<
	typename T,
	mizuiro::size_type Stride
>
bool
mizuiro::image::detail::operator!=(
	stride_pointer<T, Stride> const &_a,
	stride_pointer<T, Stride> const &_b
)
{
	return !(_a == _b);
}

#endif
