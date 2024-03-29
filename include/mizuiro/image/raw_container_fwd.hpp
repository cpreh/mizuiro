//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_RAW_CONTAINER_FWD_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_CONTAINER_FWD_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image
{

template <typename T, typename A = std::allocator<T>>
class raw_container; // IWYU pragma: export

}

#endif
