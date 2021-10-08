//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_CAN_COPY_IN_PLACE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_CAN_COPY_IN_PLACE_HPP_INCLUDED

#include <mizuiro/image/types/can_copy_in_place.hpp>

namespace mizuiro::image::algorithm
{

template <typename View1, typename View2>
using can_copy_in_place =
    mizuiro::image::types::can_copy_in_place<typename View1::format, typename View2::format>;

}

#endif
