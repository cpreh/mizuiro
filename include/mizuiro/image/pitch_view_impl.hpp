//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_PITCH_VIEW_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_PITCH_VIEW_IMPL_HPP_INCLUDED

#include <mizuiro/image/dimension_content.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <mizuiro/image/pitch_iterator_impl.hpp>
#include <mizuiro/image/pitch_view_decl.hpp>
#include <mizuiro/image/format/base_impl.hpp>

template <typename Access, typename Format, typename Constness>
mizuiro::image::pitch_view<Access, Format, Constness>::pitch_view(
    dim const &_size,
    pointer const _data,
    pitch_type const &_pitch,
    format_store_type const &_format)
    : format_base(_format), size_(_size), data_(_data), pitch_(_pitch)
{
}

template <typename Access, typename Format, typename Constness>
template <typename OtherConstness>
mizuiro::image::pitch_view<Access, Format, Constness>::pitch_view(
    mizuiro::image::pitch_view<access, format, OtherConstness> const &_other)
    : format_base(_other.format_store()),
      size_(_other.size()),
      data_(_other.data()),
      pitch_(_other.pitch())
{
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::pitch_view<Access, Format, Constness>::dim const &
mizuiro::image::pitch_view<Access, Format, Constness>::size() const
{
  return size_;
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::pitch_view<Access, Format, Constness>::pitch_type const &
mizuiro::image::pitch_view<Access, Format, Constness>::pitch() const
{
  return pitch_;
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::pitch_view<Access, Format, Constness>::iterator
mizuiro::image::pitch_view<Access, Format, Constness>::begin() const
{
  return iterator(this->size(), this->data(), this->pitch(), this->format_store());
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::pitch_view<Access, Format, Constness>::iterator
mizuiro::image::pitch_view<Access, Format, Constness>::end() const
{
  return this->begin() + static_cast<typename iterator::difference_type>(
                             mizuiro::image::dimension_content(this->size()));
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::pitch_view<Access, Format, Constness>::reference
mizuiro::image::pitch_view<Access, Format, Constness>::operator[](dim const &_index) const
{
  return *mizuiro::image::move_iterator(*this, _index);
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::pitch_view<Access, Format, Constness>::pointer
mizuiro::image::pitch_view<Access, Format, Constness>::data() const
{
  return data_;
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::pitch_view<Access, Format, Constness>::format_store_type
mizuiro::image::pitch_view<Access, Format, Constness>::format_store() const
{
  return this->format_store_base();
}

#endif
