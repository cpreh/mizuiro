//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/unlikely.hpp>
#include <mizuiro/image/dimension_impl.hpp> // IWYU pragma: keep
#include <mizuiro/image/access/advance_pointer.hpp>
#include <mizuiro/image/access/dereference.hpp>
#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/detail/pitch_iterator_decl.hpp> // IWYU pragma: export
#include <mizuiro/image/detail/pitch_iterator_position.hpp>
#include <mizuiro/image/detail/stacked_dim.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cassert>
#include <fcppt/config/external_end.hpp>

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::pitch_iterator(
    dim const &_size,
    pointer const _data,
    pitch_type const &_pitch,
    format_store_type const &_format)
    : format_base(_format),
      size_(_size),
      root_data_{_data},
      pitch_(_pitch),
      line_advance_{0},
      position_{0},
      offset_{0},
      stacked_dim_(mizuiro::image::detail::stacked_dim<difference_type>(size_))
{
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::dim const &
mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::size() const
{
  return size_;
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::difference_type
mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::offset() const
{
  return offset_;
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::pointer
mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::data() const
{
  return mizuiro::image::access::advance_pointer<Access, Constness, Format>(
      this->format_store_base(), root_data_, position_);
}

template <typename Access, typename Format, typename Constness>
mizuiro::image::detail::pitch_iterator<Access, Format, Constness> &
mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::advance(
    difference_type const _diff)
{
  // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-array-to-pointer-decay,hicpp-no-array-decay)
  assert(offset_ >= 0);

  line_advance_ = -1;

  if (_diff < 0)
  {
    *this = pitch_iterator(size_, root_data_, pitch_, this->format_store_base())
                .advance(offset_ + _diff);

    return *this;
  }

  difference_type add{
      _diff * static_cast<difference_type>(
                  mizuiro::image::access::stride<Access, Format>(this->format_store_base()))};

  for (mizuiro::size_type i = 0; i < pitch_type::static_size; ++i)
  {
    add +=
        ((_diff + offset_ % stacked_dim_.get_unsafe(i)) / stacked_dim_.get_unsafe(i)) * pitch_[i];
  }

  offset_ += _diff;

  position_ += add;

  return *this;
}

template <typename Access, typename Format, typename Constness>
void mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::increment()
{
  if (MIZUIRO_DETAIL_UNLIKELY(line_advance_ == -1))
  {
    line_advance_ =
        static_cast<difference_type>(mizuiro::image::detail::pitch_iterator_position(*this)[0]);
  }

  ++line_advance_;

  if (MIZUIRO_DETAIL_UNLIKELY(line_advance_ >= static_cast<difference_type>(size_[0])))
  {
    this->advance(1);

    line_advance_ = 0;
  }
  else
  {
    position_ += static_cast<difference_type>(
        mizuiro::image::access::stride<Access, Format>(this->format_store_base()));

    ++offset_;
  }
}

template <typename Access, typename Format, typename Constness>
void mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::decrement()
{
  this->advance(-1);
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::difference_type
mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::distance_to(
    pitch_iterator const &_other) const
{
  return _other.offset_ - offset_;
}

template <typename Access, typename Format, typename Constness>
typename mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::reference
mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::dereference() const
{
  return mizuiro::image::access::dereference<Access, Constness, Format>(
      this->format_store_base(), this->data());
}

template <typename Access, typename Format, typename Constness>
bool mizuiro::image::detail::pitch_iterator<Access, Format, Constness>::equal(
    pitch_iterator const &_other) const
{
  return position_ == _other.position_;
}

#endif
