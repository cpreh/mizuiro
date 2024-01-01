//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_DECL_HPP_INCLUDED

#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/image/format/interleaved_fwd.hpp> // IWYU pragma: keep

namespace mizuiro::image::format
{

template <typename DimType, typename ColorFormat>
class interleaved final : private mizuiro::color::format::base<ColorFormat>
{
  using format_base = mizuiro::color::format::base<ColorFormat>;

public:
  using color_format = ColorFormat;

  using format_store_type = typename format_base::format_store_type;

  using dim = DimType;

  explicit interleaved(
      format_store_type const & = mizuiro::color::format::argument<color_format>::get());

  [[nodiscard]] format_store_type format_store() const;
};

}

#endif
