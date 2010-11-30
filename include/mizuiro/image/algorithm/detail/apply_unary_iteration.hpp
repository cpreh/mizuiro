//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_UNARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_UNARY_ITERATION_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_unary_iteration_fun.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Function
>
apply_unary_iteration_fun<
	Function
> const
apply_unary_iteration(
	Function const &_fun
)
{
	return
		detail::apply_unary_iteration_fun<
			Function
		>(
			_fun
		);
}

}
}
}
}

#endif
