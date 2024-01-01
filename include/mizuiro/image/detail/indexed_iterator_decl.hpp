//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_INDEXED_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_INDEXED_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/image/indexed_ref_fwd.hpp>
#include <mizuiro/image/detail/indexed_iterator_fwd.hpp> // IWYU pragma: keep
#include <fcppt/declare_strong_typedef.hpp>

namespace mizuiro::image::detail
{

template <typename Dimension, typename Underlying>
class indexed_iterator
{
public:
  FCPPT_DECLARE_STRONG_TYPEDEF(Dimension, total_size);

  FCPPT_DECLARE_STRONG_TYPEDEF(Dimension, current);

  indexed_iterator(total_size const &, current const &, Underlying const &);

  using reference =
      mizuiro::image::indexed_ref<Dimension::static_size, typename Underlying::reference>;

  using pointer = typename Underlying::pointer;

  using difference_type = typename Underlying::difference_type;

  using format = typename Underlying::format;

  using format_store_type = typename Underlying::format_store_type;

  void advance(difference_type);

  void increment();

  void decrement();

  [[nodiscard]] difference_type distance_to(indexed_iterator const &) const;

  [[nodiscard]] reference dereference() const;

  [[nodiscard]] bool equal(indexed_iterator const &) const;

private:
  Dimension size_;

  Dimension current_;

  Underlying underlying_;
};

}

#endif
