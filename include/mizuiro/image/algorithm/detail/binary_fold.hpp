//          Copyright Carl Philipp Reh 2009 - 2016.
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
	typename View2,
	typename MakeIterator
>
inline
State
binary_fold(
	Function const &_function,
	State _state,
	View1 const &_view1,
	View2 const &_view2,
	MakeIterator const &_make_iterator
)
{
	auto it2(
		_make_iterator.begin(
			_view2
		)
	);

	for(
		auto it1(
			_make_iterator.begin(
				_view1
			)
		),
		it1end(
			_make_iterator.end(
				_view1
			)
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
