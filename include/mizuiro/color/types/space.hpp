//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_TYPES_SPACE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_SPACE_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/types/space_ns/tag.hpp>

namespace mizuiro::color::types
{

template <typename Format>
using space = decltype(space_adl(
    mizuiro::color::types::space_ns::tag(), mizuiro::color::format::make_tag_of<Format>()));

}

#endif
