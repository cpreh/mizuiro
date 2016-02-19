//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_BOUND_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BOUND_IMPL_HPP_INCLUDED

#include <mizuiro/image/bound_decl.hpp>
#include <mizuiro/image/dimension_impl.hpp>


template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::bound<
	Dim,
	ValueType
>::bound(
	dim const &_pos,
	dim const &_size
)
:
	pos_(
		_pos
	),
	size_(
		_size
	)
{
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::bound<
	Dim,
	ValueType
>::dim const &
mizuiro::image::bound<
	Dim,
	ValueType
>::pos() const
{
	return
		pos_;
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename
mizuiro::image::bound<
	Dim,
	ValueType
>::dim const &
mizuiro::image::bound<
	Dim,
	ValueType
>::size() const
{
	return
		size_;
}

#endif
