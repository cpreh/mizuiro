//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNARY_FOLD_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_UNARY_FOLD_HPP_INCLUDED


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
	typename View,
	typename MakeIterator
>
inline
State
unary_fold(
	Function const &_function,
	State _state,
	View const &_view,
	MakeIterator const &_make_iterator
)
{
	for(
		auto it(
			_make_iterator.begin(
				_view
			)
		),
		itend(
			_make_iterator.end(
				_view
			)
		);
		it != itend;
		++it
	)
		_state =
			_function(
				_state,
				*it
			);

	return
		_state;
}

}
}
}
}

#endif
