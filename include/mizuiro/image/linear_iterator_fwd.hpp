//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_LINEAR_ITERATOR_FWD_HPP_INCLUDED
#define MIZUIRO_IMAGE_LINEAR_ITERATOR_FWD_HPP_INCLUDED

#include <mizuiro/image/basic_iterator_fwd.hpp>
#include <mizuiro/image/detail/linear_iterator_fwd.hpp>

namespace mizuiro::image
{

template <typename Access, typename Format, typename Constness>
using linear_iterator = mizuiro::image::basic_iterator<
    mizuiro::image::detail::linear_iterator<Access, Format, Constness>>;

}

#endif
