//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_BOUND_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BOUND_IMPL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/bound_decl.hpp> // IWYU pragma: export
#include <mizuiro/image/dimension_impl.hpp> // IWYU pragma: keep
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep

template <mizuiro::size_type Dim, typename ValueType>
mizuiro::image::bound<Dim, ValueType>::bound(pos_t const &_pos, size_t const &_size)
    : pos_(_pos.get()), size_(_size.get())
{
}

template <mizuiro::size_type Dim, typename ValueType>
typename mizuiro::image::bound<Dim, ValueType>::dim const &
mizuiro::image::bound<Dim, ValueType>::pos() const
{
  return pos_;
}

template <mizuiro::size_type Dim, typename ValueType>
typename mizuiro::image::bound<Dim, ValueType>::dim const &
mizuiro::image::bound<Dim, ValueType>::size() const
{
  return size_;
}

#endif
