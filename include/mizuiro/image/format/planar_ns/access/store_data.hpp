//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_NS_ACCESS_STORE_DATA_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_NS_ACCESS_STORE_DATA_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/image/access/store_data_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/color_ns/types/pointer.hpp>
#include <mizuiro/image/format/planar_ns/tag.hpp>
#include <mizuiro/image/format/planar_ns/types/store.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/store.hpp>
#include <fcppt/array/init.hpp>
#include <fcppt/array/object_impl.hpp>

namespace mizuiro::image::access::store_data_ns
{

template <typename Access, typename Constness, typename ImageFormat>
mizuiro::image::types::pointer<Access, ImageFormat, Constness> store_data_adl(
    mizuiro::image::access::store_data_ns::tag,
    mizuiro::image::format::planar_ns::tag<ImageFormat>,
    Access,
    Constness,
    mizuiro::image::format::store<ImageFormat> const &,
    mizuiro::apply_const<mizuiro::image::types::store<Access, ImageFormat> &, Constness> _store)
{
  return fcppt::array::init<fcppt::array::object<
      typename mizuiro::image::types::pointer<Access, ImageFormat, Constness>::value_type,
      ImageFormat::element_count>>([&_store](mizuiro::size_type const _index)
                                   { return _store.get_unsafe(_index).data(); });
}

}

#endif
