//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_BINARY_FOLD_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_BINARY_FOLD_HPP_INCLUDED

#include <mizuiro/detail/either_binary.hpp>
#include <mizuiro/detail/either_unary.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/algorithm/detail/binary_fold.hpp>
#include <mizuiro/image/algorithm/detail/unwrap_binary_both.hpp>
#include <mizuiro/image/algorithm/detail/unwrap_binary_first.hpp>
#include <mizuiro/image/algorithm/detail/unwrap_binary_second.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename Function,
	typename State,
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
	return
		mizuiro::image::algorithm::detail::binary_fold(
			_function,
			_state,
			_view1,
			_view2,
			_make_iterator
		);
}

template<
	typename Function,
	typename State,
	typename View1,
	typename Access2,
	typename Format2,
	typename Constness2,
	typename MakeIterator
>
inline
State
binary_fold(
	Function const &_function,
	State _state,
	View1 const &_view1,
	mizuiro::image::view<
		Access2,
		Format2,
		Constness2
	> const &_view2,
	MakeIterator const &_make_iterator
)
{
	return
		mizuiro::detail::either_unary(
			mizuiro::image::algorithm::detail::unwrap_binary_second<
				Function,
				State,
				View1,
				MakeIterator
			>(
				_function,
				_state,
				_view1,
				_make_iterator
			),
			_view2.impl()
		);
}

template<
	typename Function,
	typename State,
	typename Access1,
	typename Format1,
	typename Constness1,
	typename View2,
	typename MakeIterator
>
inline
State
binary_fold(
	Function const &_function,
	State _state,
	mizuiro::image::view<
		Access1,
		Format1,
		Constness1
	> const &_view1,
	View2 const &_view2,
	MakeIterator const &_make_iterator
)
{
	return
		mizuiro::detail::either_unary(
			mizuiro::image::algorithm::detail::unwrap_binary_first<
				Function,
				State,
				View2,
				MakeIterator
			>(
				_function,
				_state,
				_view2,
				_make_iterator
			),
			_view1.impl()
		);
}

template<
	typename Function,
	typename State,
	typename Access1,
	typename Format1,
	typename Constness1,
	typename Access2,
	typename Format2,
	typename Constness2,
	typename MakeIterator
>
inline
State
binary_fold(
	Function const &_function,
	State _state,
	mizuiro::image::view<
		Access1,
		Format1,
		Constness1
	> const &_view1,
	mizuiro::image::view<
		Access2,
		Format2,
		Constness2
	> const &_view2,
	MakeIterator const &_make_iterator
)
{
	return
		mizuiro::detail::either_binary(
			mizuiro::image::algorithm::detail::unwrap_binary_both<
				Function,
				State,
				MakeIterator
			>(
				_function,
				_state,
				_make_iterator
			),
			_view1.impl(),
			_view2.impl()
		);
}

}
}
}

#endif
