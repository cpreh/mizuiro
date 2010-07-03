//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_IS_LINEAR_RANGE_HPP_INCLUDED
#define MIZUIRO_IMAGE_IS_LINEAR_RANGE_HPP_INCLUDED

#include <mizuiro/image/is_linear_iterator.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Range
>
struct is_linear_range
:
is_linear_iterator<
	typename Range::iterator
>
{};

}
}

#endif
