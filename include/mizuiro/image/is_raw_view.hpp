//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_IS_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_IS_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/access/raw.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::image
{

template <typename View>
using is_raw_view = std::is_same<typename View::access, ::mizuiro::access::raw>;

}

#endif
