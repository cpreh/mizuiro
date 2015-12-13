//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_UNARY_FOLD_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_UNARY_FOLD_HPP_INCLUDED

#include <mizuiro/detail/either_unary.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/algorithm/detail/unary_fold.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
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
	return
		mizuiro::image::algorithm::detail::unary_fold(
			_function,
			_state,
			_view,
			_make_iterator
		);
}

template<
	typename State,
	typename Function,
	typename Access,
	typename Format,
	typename Constness,
	typename MakeIterator
>
inline
State
unary_fold(
	Function const &_function,
	State _state,
	mizuiro::image::view<
		Access,
		Format,
		Constness
	> const &_view,
	MakeIterator const &_make_iterator
)
{
	return
		mizuiro::detail::either_unary(
			[
				&_function,
				_state,
				&_make_iterator
			](
				auto const &_view_inner
			)
			{
				return
					mizuiro::image::algorithm::detail::unary_fold(
						_function,
						_state,
						_view_inner,
						_make_iterator
					);
			},
			_view.impl()
		);
}

}
}
}

#endif
