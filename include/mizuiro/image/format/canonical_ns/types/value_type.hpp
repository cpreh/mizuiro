//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_VALUE_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_VALUE_TYPE_HPP_INCLUDED

#include <mizuiro/image/format/canonical_ns/tag.hpp>
#include <mizuiro/image/types/value_type_ns/tag.hpp>

namespace mizuiro::image::types::value_type_ns
{

template <typename Format>
Format::element_type value_type_adl(
    mizuiro::image::types::value_type_ns::tag, mizuiro::image::format::canonical_ns::tag<Format>);

}

#endif
