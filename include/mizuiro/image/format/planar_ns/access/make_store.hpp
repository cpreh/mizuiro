//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_NS_ACCESS_MAKE_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_NS_ACCESS_MAKE_STORE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_content.hpp>
#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/access/make_store_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/planar_ns/tag.hpp>
#include <mizuiro/image/types/store.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>

namespace mizuiro::image::access::make_store_ns
{

template <typename Access, typename ImageFormat>
mizuiro::image::types::store<Access, ImageFormat> make_store_adl(
    mizuiro::image::access::make_store_ns::tag,
    mizuiro::image::format::planar_ns::tag<ImageFormat>,
    Access,
    mizuiro::image::format::store<ImageFormat> const &_format,
    typename ImageFormat::dim const &_dim)
{
  return fcppt::array::init<fcppt::array::object<
      typename mizuiro::image::types::store<Access, ImageFormat>::value_type,
      ImageFormat::element_count>>(
      [&_dim, &_format](mizuiro::size_type)
      {
        return typename mizuiro::image::types::store<Access, ImageFormat>::value_type(
            mizuiro::image::dimension_content(_dim) *
            mizuiro::image::access::stride<Access, ImageFormat>(_format));
      });
}

}

#endif
