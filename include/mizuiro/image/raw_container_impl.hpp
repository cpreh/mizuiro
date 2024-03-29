//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_RAW_CONTAINER_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_CONTAINER_IMPL_HPP_INCLUDED

#include <mizuiro/image/raw_container_decl.hpp> // IWYU pragma: export
#include <fcppt/preprocessor/ignore_unsafe_buffer_usage.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>

FCPPT_PP_PUSH_WARNING
FCPPT_PP_IGNORE_UNSAFE_BUFFER_USAGE

template <typename T, typename A>
mizuiro::image::raw_container<T, A>::raw_container()
    : allocator(), data_(nullptr), data_end_(nullptr)
{
}

template <typename T, typename A>
mizuiro::image::raw_container<T, A>::raw_container(size_type const _size) : allocator()
// Dont' initialize data_ and data_end_
{
  this->allocate(_size);
}

template <typename T, typename A>
mizuiro::image::raw_container<T, A>::raw_container(raw_container const &_other) : allocator()
// Dont' initialize data_ and data_end_
{
  this->copy(_other);
}

template <typename T, typename A>
mizuiro::image::raw_container<T, A>::raw_container(raw_container &&_other) noexcept
    : allocator(), data_(_other.data_), data_end_(_other.data_end_)
{
  _other.after_move();
}

template <typename T, typename A>
mizuiro::image::raw_container<T, A> &mizuiro::image::raw_container<
    T,
    A>::operator=( // NOLINT(cert-oop54-cpp)
    raw_container const &_other)
{
  if (this == &_other)
  {
    return *this;
  }

  this->destroy();

  this->copy(_other);

  return *this;
}

template <typename T, typename A>
mizuiro::image::raw_container<T, A> &
mizuiro::image::raw_container<T, A>::operator=(raw_container &&_other) noexcept
{
  if (this == &_other)
  {
    return *this;
  }

  this->destroy();

  data_ = _other.data_;

  data_end_ = _other.data_end_;

  _other.after_move();

  return *this;
}

namespace mizuiro::image
{
template <typename T, typename A>
raw_container<T, A>::~raw_container()
{
  this->destroy();
}
}

template <typename T, typename A>
void mizuiro::image::raw_container<T, A>::resize(size_type const _size)
{
  this->destroy();

  this->allocate(_size);
}

template <typename T, typename A>
typename mizuiro::image::raw_container<T, A>::pointer mizuiro::image::raw_container<T, A>::data()
{
  return data_;
}

template <typename T, typename A>
typename mizuiro::image::raw_container<T, A>::const_pointer
mizuiro::image::raw_container<T, A>::data() const
{
  return data_;
}

template <typename T, typename A>
typename mizuiro::image::raw_container<T, A>::pointer
mizuiro::image::raw_container<T, A>::data_end()
{
  return data_end_;
}

template <typename T, typename A>
typename mizuiro::image::raw_container<T, A>::const_pointer
mizuiro::image::raw_container<T, A>::data_end() const
{
  return data_end_;
}

template <typename T, typename A>
typename mizuiro::image::raw_container<T, A>::size_type
mizuiro::image::raw_container<T, A>::size() const
{
  return static_cast<size_type>(data_end_ - data_);
}

template <typename T, typename A>
void mizuiro::image::raw_container<T, A>::allocate(size_type const _size)
{
  data_ = allocator.allocate(_size);

  data_end_ = data_ + _size;
}

template <typename T, typename A>
void mizuiro::image::raw_container<T, A>::copy(raw_container const &_other)
{
  this->allocate(_other.size());

  if (_other.data())
  {
    std::uninitialized_copy(_other.data(), _other.data_end(), this->data());
  }
}

template <typename T, typename A>
void mizuiro::image::raw_container<T, A>::destroy()
{
  if (data_)
  {
    allocator.deallocate(data_, this->size());
  }
}

template <typename T, typename A>
void mizuiro::image::raw_container<T, A>::after_move()
{
  data_ = nullptr;

  data_end_ = nullptr;
}

FCPPT_PP_POP_WARNING

#endif
