//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED

#include <mizuiro/image/algorithm/unary_iteration.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename View,
	typename Fun
>
Fun const
for_each(
	View const &_view,
	Fun const &_fun
)
{
	algorithm::unary_iteration(
		_fun,
		_view
	);

	return _fun;
}

}
}
}

#endif
