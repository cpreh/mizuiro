//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_BINARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_BINARY_ITERATION_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Function,
	typename View1,
	typename View2
>
void
binary_iteration(
	Function const &_function,
	View1 const &_view1,
	View2 const &_view2
)
{
	typename View2::iterator it2(
		_view2.begin()
	);

	for(
		typename View1::iterator
			it1(
				_view1.begin()
			),
			it1end(
				_view1.end()
			);
		it1 != it1end;
		++it1, ++it2
	)
		_function(
			*it1,
			*it2
		);
}

}
}
}
}

#endif
