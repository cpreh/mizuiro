//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_CAN_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_CAN_COPY_HPP_INCLUDED

#include <mizuiro/image/format/canonical_ns/tag.hpp>
#include <mizuiro/image/types/can_copy_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image::types::can_copy_ns
{

template <typename ImageFormat1, typename ImageFormat2>
std::is_same<typename ImageFormat1::element_type, typename ImageFormat2::element_type> can_copy_adl(
    mizuiro::image::types::can_copy_ns::tag,
    mizuiro::image::format::canonical_ns::tag<ImageFormat1>,
    mizuiro::image::format::canonical_ns::tag<ImageFormat2>);

}

#endif
