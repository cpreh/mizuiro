//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_ALGORITHM_EQUAL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_EQUAL_HPP_INCLUDED

#include <mizuiro/detail/equal.hpp>
#include <mizuiro/image/algorithm/compare.hpp>

namespace mizuiro::image::algorithm
{

template <typename View1, typename View2>
bool equal(View1 const &_src1, View2 const &_src2)
{
  return mizuiro::image::algorithm::compare(_src1, _src2, mizuiro::detail::equal());
}

}

#endif
