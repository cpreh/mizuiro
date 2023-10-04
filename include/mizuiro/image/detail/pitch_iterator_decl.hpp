//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_ITERATOR_DECL_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/image/pitch_type.hpp>
#include <mizuiro/image/detail/pitch_iterator_fwd.hpp>
#include <mizuiro/image/detail/stacked_dim_array.hpp>
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>

namespace mizuiro::image::detail
{

template <typename Access, typename Format, typename Constness>
class pitch_iterator : private mizuiro::image::format::base<Format>
{
  using format_base = mizuiro::image::format::base<Format>;

public:
  using access = Access;

  using format = Format;

  using constness = Constness;

  using format_store_type = typename format_base::format_store_type;

  using dim = typename format::dim;

  using pitch_type = mizuiro::image::pitch_type<dim>;

  using reference = mizuiro::image::types::reference<access, format, constness>;

  using pointer = mizuiro::image::types::pointer<access, format, constness>;

  using difference_type = mizuiro::difference_type;

  pitch_iterator(dim const &, pointer data, pitch_type const &, format_store_type const &);

  [[nodiscard]] dim const &size() const;

  [[nodiscard]] difference_type offset() const;

  [[nodiscard]] pointer data() const;

  pitch_iterator &advance(difference_type);

  void increment();

  void decrement();

  [[nodiscard]] difference_type distance_to(pitch_iterator const &) const;

  [[nodiscard]] reference dereference() const;

  [[nodiscard]] bool equal(pitch_iterator const &) const;

private:
  dim size_;

  pointer root_data_;

  pitch_type pitch_;

  difference_type line_advance_; // NOLINT(cppcoreguidelines-use-default-member-init,modernize-use-default-member-init)

  difference_type position_; // NOLINT(cppcoreguidelines-use-default-member-init,modernize-use-default-member-init)

  difference_type offset_; // NOLINT(cppcoreguidelines-use-default-member-init,modernize-use-default-member-init)

  using stacked_dim_array = mizuiro::image::detail::stacked_dim_array<dim, difference_type>;

  stacked_dim_array stacked_dim_;
};

}

#endif
