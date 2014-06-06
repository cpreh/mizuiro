//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_BINARY_FOLD_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_BINARY_FOLD_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename State,
	typename Function,
	typename View1,
	typename View2
>
inline
State
binary_fold(
	Function const &_function,
	State _state,
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
		_state =
			_function(
				_state,
				*it1,
				*it2
			);

	return
		_state;
}

}
}
}
}

#endif
