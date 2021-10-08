//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_TO_COLOR_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_TO_COLOR_STORE_HPP_INCLUDED

#include <mizuiro/color/format/store_impl.hpp>
#include <mizuiro/detail/map_format_store.hpp>
#include <mizuiro/image/format/store_impl.hpp>

namespace mizuiro::image::format
{

template <typename ImageFormat>
inline mizuiro::color::format::store<typename ImageFormat::color_format>
to_color_store(mizuiro::image::format::store<ImageFormat> const &_format)
{
  // Currently, interleaved formats have state if their color
  // formats have state. This code could be simplified if this
  // will be always the case.
  return mizuiro::detail::map_format_store<typename ImageFormat::color_format>(
      _format, [](auto const &_store) { return _store.format_store(); });
}

}

#endif
