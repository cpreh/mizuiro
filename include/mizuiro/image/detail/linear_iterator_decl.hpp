//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_LINEAR_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_LINEAR_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/image/detail/linear_iterator_fwd.hpp> // IWYU pragma: keep
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>

namespace mizuiro::image::detail
{

template <typename Access, typename Format, typename Constness>
class linear_iterator : private mizuiro::image::format::base<Format>
{
public:
  using format_base = mizuiro::image::format::base<Format>;

  using format_store_type = format_base::format_store_type;

  using access = Access;

  using format = Format;

  using constness = Constness;

  using reference = mizuiro::image::types::reference<access, format, constness>;

  using pointer = mizuiro::image::types::pointer<access, format, constness>;

  using difference_type = mizuiro::difference_type;

  linear_iterator(pointer, format_store_type const &);

  [[nodiscard]] pointer data() const;

  void advance(difference_type);

  void increment();

  void decrement();

  [[nodiscard]] difference_type distance_to(linear_iterator const &) const;

  [[nodiscard]] reference dereference() const;

  [[nodiscard]] bool equal(linear_iterator const &) const;

private:
  pointer data_;
};

}

#endif
