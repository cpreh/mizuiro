#ifndef MIZUIRO_COLOR_DETAIL_STRIDE_POINTER_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_STRIDE_POINTER_IMPL_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_decl.hpp>
#include <cassert>

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::color::detail::stride_pointer<T, Stride>::stride_pointer(
	T const base_
)
:
	base_(base_)
{}

template<
	typename T,
	mizuiro::size_type Stride
>
template<
	typename OtherT
>
mizuiro::color::detail::stride_pointer<T, Stride>::stride_pointer(
	stride_pointer<
		OtherT,
		Stride
	> const &other
)
:
	base_(other.get())
{}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::color::detail::stride_pointer<T, Stride> &
mizuiro::color::detail::stride_pointer<T, Stride>::operator+=(
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

mizuiro::color::detail::stride_pointer<T, Stride> &
mizuiro::color::detail::stride_pointer<T, Stride>::operator-=(
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
mizuiro::color::detail::stride_pointer<T, Stride> &
mizuiro::color::detail::stride_pointer<T, Stride>::operator++()
{
	base_ += sstride;
	return *this;
}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::color::detail::stride_pointer<T, Stride> &
mizuiro::color::detail::stride_pointer<T, Stride>::operator--()
{
	base_ -= sstride;
	return *this;
}

template<
	typename T,
	mizuiro::size_type Stride
>
typename mizuiro::color::detail::stride_pointer<T, Stride>::reference
mizuiro::color::detail::stride_pointer<T, Stride>::operator*() const
{
	return *base_;
}

template<
	typename T,
	mizuiro::size_type Stride
>
typename mizuiro::color::detail::stride_pointer<T, Stride>::reference
mizuiro::color::detail::stride_pointer<T, Stride>::operator[](
	size_type const index
) const
{
	return *(*this + index);
}

template<
	typename T,
	mizuiro::size_type Stride
>
typename mizuiro::color::detail::stride_pointer<T, Stride>::difference_type
mizuiro::color::detail::stride_pointer<T, Stride>::operator-(
	stride_pointer const &other
) const
{
	assert(
		(base_ - other.base_) % sstride == 0
	);

	return (base_ - other.base_) / sstride;
}

template<
	typename T,
	mizuiro::size_type Stride
>
bool
mizuiro::color::detail::stride_pointer<T, Stride>::operator==(
	stride_pointer const &other
) const
{
	return base_ == other.base_;
}

template<
	typename T,
	mizuiro::size_type Stride
>
T
mizuiro::color::detail::stride_pointer<T, Stride>::get() const
{
	return base_;
}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::color::detail::stride_pointer<T, Stride> const
mizuiro::color::detail::operator +(
	stride_pointer<T, Stride> p,
	typename stride_pointer<T, Stride>::difference_type const d
)
{
	return p += d;
}

template<
	typename T,
	mizuiro::size_type Stride
>
mizuiro::color::detail::stride_pointer<T, Stride> const
mizuiro::color::detail::operator -(
	stride_pointer<T, Stride> p,
	typename stride_pointer<T, Stride>::difference_type const d
)
{
	return p -= d;
}

template<
	typename T,
	mizuiro::size_type Stride
>
bool
mizuiro::color::detail::operator!=(
	stride_pointer<T, Stride> const &a,
	stride_pointer<T, Stride> const &b
)
{
	return !(a == b);
}

#endif
