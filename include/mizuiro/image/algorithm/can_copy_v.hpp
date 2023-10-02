//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_CAN_COPY_V_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_CAN_COPY_V_HPP_INCLUDED

#include <mizuiro/image/algorithm/can_copy.hpp>

namespace mizuiro::image::algorithm
{

/**
\brief Tests statically whether two views can be copied
*/
template <typename View1, typename View2>
// NOLINTNEXTLINE(modernize-type-traits)
constexpr inline bool can_copy_v = mizuiro::image::algorithm::can_copy<View1, View2>::value;

}

#endif
