//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_UNARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_UNARY_ITERATION_HPP_INCLUDED

#include <mizuiro/image/algorithm/unary_fold.hpp>
#include <mizuiro/image/algorithm/detail/dummy_state.hpp>
#include <mizuiro/image/algorithm/detail/iteration_to_fold_function.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename Function,
	typename View,
	typename MakeIterator
>
inline
void
unary_iteration(
	Function const &_function,
	View const &_view,
	MakeIterator const &_make_iterator
)
{
	mizuiro::image::algorithm::unary_fold(
		mizuiro::image::algorithm::detail::iteration_to_fold_function<
			Function
		>(
			_function
		),
		mizuiro::image::algorithm::detail::dummy_state(),
		_view,
		_make_iterator
	);
}

}
}
}

#endif
