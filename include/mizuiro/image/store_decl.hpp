//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_DECL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/empty_fwd.hpp>
#include <mizuiro/no_init_fwd.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/image/dimension_decl.hpp> // IWYU pragma: keep
#include <mizuiro/image/linear_view_fwd.hpp>
#include <mizuiro/image/store_fwd.hpp> // IWYU pragma: keep
#include <mizuiro/image/format/argument.hpp>
#include <mizuiro/image/format/base_decl.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/store.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>

namespace mizuiro::image
{

template <typename Format, typename Access>
class store : private mizuiro::image::format::base<Format>
{
  using format_base = mizuiro::image::format::base<Format>;

public:
  using access = Access;

  using format = Format;

  using format_store_type = typename format_base::format_store_type;

  using pointer = mizuiro::image::types::pointer<access, format, mizuiro::nonconst_tag>;

  using const_pointer = mizuiro::image::types::pointer<access, format, mizuiro::const_tag>;

  using dim = typename format::dim;

  using value_type = mizuiro::image::types::value_type<format>;

  using view_type = mizuiro::image::linear_view<access, format, mizuiro::nonconst_tag>;

  using const_view_type = mizuiro::image::linear_view<access, format, mizuiro::const_tag>;

  FCPPT_PP_PUSH_WARNING
  FCPPT_PP_DISABLE_VC_WARNING(4686)

  store(
      dim const &,
      mizuiro::no_init const &,
      format_store_type const & = mizuiro::image::format::argument<format>::get());

  explicit store(
      mizuiro::empty const &,
      format_store_type const & = mizuiro::image::format::argument<format>::get());

  store(
      dim const &,
      value_type const &,
      format_store_type const & = mizuiro::image::format::argument<format>::get());

  template <typename Function>
  store(
      dim const &,
      Function const &,
      format_store_type const & = mizuiro::image::format::argument<format>::get());

  FCPPT_PP_POP_WARNING

  [[nodiscard]] pointer data();

  [[nodiscard]] const_pointer data() const;

  [[nodiscard]] view_type view();

  [[nodiscard]] const_view_type view() const;

  [[nodiscard]] dim const &size() const;

  [[nodiscard]] format_store_type format_store() const;

private:
  dim size_;

  using container = mizuiro::image::types::store<access, format>;

  container data_;
};

}

#endif
