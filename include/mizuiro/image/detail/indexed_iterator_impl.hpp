//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_INDEXED_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_INDEXED_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/indexed_ref_impl.hpp> // IWYU pragma: keep
#include <mizuiro/image/detail/decrement_dim.hpp>
#include <mizuiro/image/detail/increment_dim.hpp>
#include <mizuiro/image/detail/indexed_iterator_decl.hpp> // IWYU pragma: export
#include <mizuiro/image/detail/relative_position.hpp>
#include <fcppt/strong_typedef_impl.hpp> // IWYU pragma: keep

template <typename Dimension, typename Underlying>
mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::indexed_iterator(
    total_size const &_size, current const &_current, Underlying const &_underlying)
    : size_(_size.get()), current_(_current.get()), underlying_(_underlying)
{
}

template <typename Dimension, typename Underlying>
void mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::advance(
    difference_type const _diff)
{
  underlying_ += _diff;

  current_ = mizuiro::image::detail::relative_position(size_, current_);
}

template <typename Dimension, typename Underlying>
void mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::increment()
{
  ++underlying_;

  current_ = mizuiro::image::detail::increment_dim(size_, current_);
}

template <typename Dimension, typename Underlying>
void mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::decrement()
{
  --underlying_;

  current_ = mizuiro::image::detail::decrement_dim(size_, current_);
}

template <typename Dimension, typename Underlying>
mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::difference_type
mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::distance_to(
    indexed_iterator const &_other) const
{
  return this->distance_to(_other);
}

template <typename Dimension, typename Underlying>
mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::reference
mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::dereference() const
{
  return reference(current_, *underlying_);
}

template <typename Dimension, typename Underlying>
bool mizuiro::image::detail::indexed_iterator<Dimension, Underlying>::equal(
    indexed_iterator const &_other) const
{
  return underlying_ == _other.underlying_;
}

#endif
