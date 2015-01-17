//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_BINARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_BINARY_ITERATION_HPP_INCLUDED

#include <mizuiro/image/algorithm/binary_fold.hpp>
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
	typename View1,
	typename View2,
	typename MakeIterator
>
inline
void
binary_iteration(
	Function const &_function,
	View1 const &_view1,
	View2 const &_view2,
	MakeIterator const &_make_iterator
)
{
	mizuiro::image::algorithm::binary_fold(
		mizuiro::image::algorithm::detail::iteration_to_fold_function<
			Function
		>(
			_function
		),
		mizuiro::image::algorithm::detail::dummy_state(),
		_view1,
		_view2,
		_make_iterator
	);
}

}
}
}

#endif
