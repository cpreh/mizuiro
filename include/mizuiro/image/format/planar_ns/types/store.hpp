//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_NS_TYPES_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_NS_TYPES_STORE_HPP_INCLUDED

#include <mizuiro/access/store_unit.hpp>
#include <mizuiro/image/raw_container_impl.hpp>
#include <mizuiro/image/format/planar_ns/tag.hpp>
#include <mizuiro/image/types/store_unit.hpp>
#include <mizuiro/image/types/store_ns/tag.hpp>
#include <fcppt/array/object_impl.hpp>

namespace mizuiro::image::types::store_ns
{

template <typename Access, typename ImageFormat>
fcppt::array::object<
    mizuiro::image::raw_container<
        mizuiro::access::store_unit<Access, mizuiro::image::types::store_unit<ImageFormat>>>,
    ImageFormat::element_count>
    store_adl(
        mizuiro::image::types::store_ns::tag,
        Access,
        mizuiro::image::format::planar_ns::tag<ImageFormat>);

}

#endif
