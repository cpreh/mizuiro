#ifndef MIZUIRO_IMAGE_BOUND_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BOUND_IMPL_HPP_INCLUDED

#include <mizuiro/image/bound_decl.hpp>
#include <mizuiro/image/dimension_impl.hpp>

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::bound<Dim, ValueType>::bound(
	dim_type const &positions_,
	dim_type const &dimensions_
)
:
	positions_(positions_),
	dimensions_(dimensions_)
{}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::bound<Dim, ValueType>::dim_type const &
mizuiro::image::bound<Dim, ValueType>::positions() const
{
	return positions_;
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::bound<Dim, ValueType>::dim_type const &
mizuiro::image::bound<Dim, ValueType>::dimensions() const
{
	return dimensions_;
}

#endif
