//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNARY_ITERATION_HPP_INCLUDED


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
	typename View
>
void
unary_iteration(
	Function const &_function,
	View const &_view
)
{
	for(
		typename View::iterator
			it(
				_view.begin()
			),
			itend(
				_view.end()
			);
		it != itend;
		++it
	)
		_function(
			*it
		);
}

}
}
}
}

#endif
