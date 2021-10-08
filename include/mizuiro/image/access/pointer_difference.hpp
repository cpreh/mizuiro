//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ACCESS_POINTER_DIFFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_POINTER_DIFFERENCE_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/image/access/pointer_difference_ns/tag.hpp>
#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/tag_of_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>

namespace mizuiro::image::access
{

template <typename Access, typename Constness, typename Format>
mizuiro::difference_type pointer_difference(
    mizuiro::image::format::store<Format> const &_format,
    mizuiro::image::types::pointer<Access, Format, Constness> const _pointer1,
    mizuiro::image::types::pointer<Access, Format, Constness> const _pointer2)
{
  return pointer_difference_adl(
      mizuiro::image::access::pointer_difference_ns::tag(),
      mizuiro::image::format::make_tag_of<Format>(),
      Access(),
      Constness(),
      _format,
      _pointer1,
      _pointer2);
}

}

#endif
