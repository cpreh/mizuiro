//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ACCESS_DEREFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_DEREFERENCE_HPP_INCLUDED

#include <mizuiro/image/access/dereference_ns/tag.hpp>
#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>

namespace mizuiro::image::access
{

template <typename Access, typename Constness, typename ImageFormat>
mizuiro::image::types::reference<Access, ImageFormat, Constness> dereference(
    mizuiro::image::format::store<ImageFormat> const &_format,
    mizuiro::image::types::pointer<Access, ImageFormat, Constness> const _data)
{
  return dereference_adl(
      mizuiro::image::access::dereference_ns::tag(),
      Access(),
      mizuiro::image::format::make_tag_of<ImageFormat>(),
      Constness(),
      _format,
      _data);
}

}

#endif
