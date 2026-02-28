//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/image/linear_iterator_decl.hpp>
#include <mizuiro/image/pitch_iterator_decl.hpp>
#include <mizuiro/image/detail/iterator_fwd.hpp> // IWYU pragma: keep
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <fcppt/variant/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image::detail
{

template <typename Access, typename Format, typename Constness>
class iterator
{
public:
  using access = Access;

  using format = Format;

  using constness = Constness;

  using pitch_iterator = mizuiro::image::pitch_iterator<access, format, constness>;

  using linear_iterator = mizuiro::image::linear_iterator<access, format, constness>;

  static_assert(
      std::is_same_v<
          typename pitch_iterator::format_store_type,
          typename linear_iterator::format_store_type>,
      "pitch_iterator and linear_iterator need the same format store");

  using format_store_type = pitch_iterator::format_store_type;

  using internal_type = fcppt::variant::object<pitch_iterator, linear_iterator>;

  using reference = mizuiro::image::types::reference<access, format, constness>;

  using pointer = mizuiro::image::types::pointer<access, format, constness>;

  using difference_type = mizuiro::difference_type;

  explicit iterator(internal_type const &);

  [[nodiscard]] internal_type const &internal() const;

  [[nodiscard]] pointer data() const;

  void advance(difference_type);

  void increment();

  void decrement();

  [[nodiscard]] difference_type distance_to(iterator const &) const;

  [[nodiscard]] reference dereference() const;

  [[nodiscard]] bool equal(iterator const &) const;

private:
  internal_type internal_;
};

}

#endif
