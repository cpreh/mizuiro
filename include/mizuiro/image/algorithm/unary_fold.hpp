//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_UNARY_FOLD_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_UNARY_FOLD_HPP_INCLUDED

#include <mizuiro/detail/variant_apply_unary.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/algorithm/detail/unary_fold.hpp>
#include <mizuiro/image/algorithm/detail/unwrap_unary.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename State,
	typename Function,
	typename View
>
inline
State
unary_fold(
	Function const &_function,
	State _state,
	View const &_view
)
{
	return
		mizuiro::image::algorithm::detail::unary_fold(
			_function,
			_state,
			_view
		);
}

template<
	typename State,
	typename Function,
	typename Access,
	typename Format,
	typename Constness
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
	> const &_view
)
{
	return
		mizuiro::detail::variant_apply_unary(
			mizuiro::image::algorithm::detail::unwrap_unary<
				Function,
				State
			>(
				_function,
				_state
			),
			_view.impl()
		);
}

}
}
}

#endif
