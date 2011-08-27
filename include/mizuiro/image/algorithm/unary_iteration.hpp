//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_UNARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_UNARY_ITERATION_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/unary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/unwrap_unary.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/detail/variant_apply_unary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
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
	algorithm::detail::unary_iteration(
		_function,
		_view
	);
}

template<
	typename Function,
	typename Access,
	typename Format,
	typename Constness
>
void
unary_iteration(
	Function const &_function,
	image::view<
		Access,
		Format,
		Constness
	> const &_view
)
{
	mizuiro::detail::variant_apply_unary(
		algorithm::detail::unwrap_unary<
			Function
		>(
			_function
		),
		_view.impl()
	);
}

}
}
}

#endif
