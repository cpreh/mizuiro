//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ACCESS_STORE_DATA_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_STORE_DATA_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/image/access/store_data_ns/tag.hpp>
#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/store.hpp>

namespace mizuiro::image::access
{

template <typename Access, typename Constness, typename ImageFormat>
inline mizuiro::image::types::pointer<Access, ImageFormat, Constness> store_data(
    mizuiro::image::format::store<ImageFormat> const &_format,
    mizuiro::apply_const<mizuiro::image::types::store<Access, ImageFormat> &, Constness> _store)
{
  return store_data_adl(
      mizuiro::image::access::store_data_ns::tag(),
      mizuiro::image::format::make_tag_of<ImageFormat>(),
      Access{},
      Constness{},
      _format,
      _store);
}

}

#endif
