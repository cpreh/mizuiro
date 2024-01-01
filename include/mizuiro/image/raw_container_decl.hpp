//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_RAW_CONTAINER_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_CONTAINER_DECL_HPP_INCLUDED

#include <mizuiro/image/raw_container_fwd.hpp> // IWYU pragma: keep
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image
{

template <typename T, typename A>
class raw_container
{
public:
  using value_type = T;

  using allocator_type = A;

  using pointer = typename std::allocator_traits<A>::pointer;

  using const_pointer = typename std::allocator_traits<A>::const_pointer;

  using size_type = typename std::allocator_traits<A>::size_type;

  raw_container();

  explicit raw_container(size_type);

  raw_container(raw_container const &);

  raw_container(raw_container &&) noexcept;

  raw_container &operator=(raw_container const &);

  raw_container &operator=(raw_container &&) noexcept;

  ~raw_container();

  void resize(size_type);

  [[nodiscard]] pointer data();

  [[nodiscard]] const_pointer data() const;

  [[nodiscard]] pointer data_end();

  [[nodiscard]] const_pointer data_end() const;

  [[nodiscard]] size_type size() const;

private:
  void allocate(size_type);

  void copy(raw_container const &);

  void destroy();

  void after_move();

  allocator_type allocator;

  pointer data_, data_end_;
};

}

#endif
