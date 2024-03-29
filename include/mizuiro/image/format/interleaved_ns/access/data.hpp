//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_ACCESS_DATA_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_ACCESS_DATA_HPP_INCLUDED

#include <mizuiro/image/access/data_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/color_ns/types/pointer.hpp> // IWYU pragma: keep
#include <mizuiro/image/format/color_ns/types/reference.hpp> // IWYU pragma: keep
#include <mizuiro/image/format/interleaved_ns/tag.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>

namespace mizuiro::image::access::data_ns
{

template <typename Access, typename ImageFormat, typename Constness>
mizuiro::image::types::pointer<Access, ImageFormat, Constness> data_adl(
    mizuiro::image::access::data_ns::tag,
    Access const &,
    mizuiro::image::format::interleaved_ns::tag<ImageFormat>,
    Constness,
    mizuiro::image::format::store<ImageFormat> const &,
    mizuiro::image::types::reference<Access, ImageFormat, Constness> const &_ref)
{
  return _ref.data();
}

}

#endif
