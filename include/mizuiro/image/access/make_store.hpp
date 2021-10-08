//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ACCESS_MAKE_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_MAKE_STORE_HPP_INCLUDED

#include <mizuiro/image/access/make_store_ns/tag.hpp>
#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/types/store.hpp>

namespace mizuiro::image::access
{

template <typename Access, typename ImageFormat>
mizuiro::image::types::store<Access, ImageFormat> make_store(
    mizuiro::image::format::store<ImageFormat> const &_format, typename ImageFormat::dim const _dim)
{
  return make_store_adl(
      mizuiro::image::access::make_store_ns::tag(),
      mizuiro::image::format::make_tag_of<ImageFormat>(),
      Access{},
      _format,
      _dim);
}

}

#endif
