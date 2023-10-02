//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_TYPES_NEEDS_PREPARE_V_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_NEEDS_PREPARE_V_HPP_INCLUDED

#include <mizuiro/image/types/needs_prepare.hpp>

namespace mizuiro::image::types
{

template <typename Format>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool needs_prepare_v = mizuiro::image::types::needs_prepare<Format>::value;
}

#endif
