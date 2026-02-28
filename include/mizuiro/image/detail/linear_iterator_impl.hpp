//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_LINEAR_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_LINEAR_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/access/advance_pointer.hpp>
#include <mizuiro/image/access/dereference.hpp>
#include <mizuiro/image/access/pointer_difference.hpp>
#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/detail/linear_iterator_decl.hpp> // IWYU pragma: export
#include <mizuiro/image/format/base_impl.hpp> // IWYU pragma: keep
#include <fcppt/array/comparison.hpp> // IWYU pragma: keep

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::linear_iterator<Access, Format, Constness>::linear_iterator(
    pointer const _data, format_store_type const &_format)
    : format_base(_format), data_(_data)
{
}

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::linear_iterator<Access, Format, Constness>::pointer
mizuiro::image::detail::linear_iterator<Access, Format, Constness>::data() const
{
  return data_;
}

template <typename Access, typename Format, typename Constness>
void mizuiro::image::detail::linear_iterator<Access, Format, Constness>::advance(
    difference_type const _diff)
{
  data_ = mizuiro::image::access::advance_pointer<Access, Constness, Format>(
      this->format_store_base(),
      data_,
      _diff * static_cast<difference_type>(
                  mizuiro::image::access::stride<Access, Format>(this->format_store_base())));
}

template <typename Access, typename Format, typename Constness>
inline void mizuiro::image::detail::linear_iterator<Access, Format, Constness>::increment()
{
  this->advance(1);
}

template <typename Access, typename Format, typename Constness>
inline void mizuiro::image::detail::linear_iterator<Access, Format, Constness>::decrement()
{
  this->advance(-1);
}

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::linear_iterator<Access, Format, Constness>::difference_type
mizuiro::image::detail::linear_iterator<Access, Format, Constness>::distance_to(
    linear_iterator const &_other) const
{
  return mizuiro::image::access::pointer_difference<Access, Constness, Format>(
             this->format_store_base(), _other.data_, data_) /
         static_cast<difference_type>(
             mizuiro::image::access::stride<Access, Format>(this->format_store_base()));
}

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::linear_iterator<Access, Format, Constness>::reference
mizuiro::image::detail::linear_iterator<Access, Format, Constness>::dereference() const
{
  return mizuiro::image::access::dereference<Access, Constness, Format>(
      this->format_store_base(), data_);
}

template <typename Access, typename Format, typename Constness>
bool mizuiro::image::detail::linear_iterator<Access, Format, Constness>::equal(
    linear_iterator const &_other) const
{
  return data_ == _other.data_;
}

#endif
