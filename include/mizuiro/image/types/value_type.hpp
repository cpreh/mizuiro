//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_TYPES_VALUE_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_VALUE_TYPE_HPP_INCLUDED

#include <mizuiro/image/format/make_tag_of.hpp>
#include <mizuiro/image/types/value_type_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image::types
{

template <typename Format>
using value_type = decltype(value_type_adl(
    std::declval<mizuiro::image::types::value_type_ns::tag>(),
    mizuiro::image::format::make_tag_of<Format>()));

}

#endif
