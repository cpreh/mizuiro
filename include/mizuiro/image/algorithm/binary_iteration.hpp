//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_BINARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_BINARY_ITERATION_HPP_INCLUDED

#include <mizuiro/detail/variant_apply_binary.hpp>
#include <mizuiro/detail/variant_apply_unary.hpp>
#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/image/algorithm/detail/binary_iteration.hpp>
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
	algorithm::detail::binary_iteration(
		_function,
		_view1,
		_view2
	);
}

template<
	typename Function,
	typename View1,
	typename Access2,
	typename Format2,
	typename Constness2
>
void
binary_iteration(
	Function const &_function,
	View1 const &_view1,
	image::view<
		Access2,
		Format2,
		Constness2
	> const &_view2
)
{
	mizuiro::detail::variant_apply_unary(
		algorithm::detail::unwrap_binary_second<
			Function,
			View1
		>(
			_function,
			_view1
		),
		_view2.impl()
	);
}

template<
	typename Function,
	typename Access1,
	typename Format1,
	typename Constness1,
	typename View2
>
void
binary_iteration(
	Function const &_function,
	image::view<
		Access1,
		Format1,
		Constness1
	> const &_view1,
	View2 const &_view2
)
{
	mizuiro::detail::variant_apply_unary(
		algorithm::detail::unwrap_binary_first<
			Function,
			View2
		>(
			_function,
			_view2
		),
		_view1.impl()
	);
}

template<
	typename Function,
	typename Access1,
	typename Format1,
	typename Constness1,
	typename Access2,
	typename Format2,
	typename Constness2
>
void
binary_iteration(
	Function const &_function,
	image::view<
		Access1,
		Format1,
		Constness1
	> const &_view1,
	image::view<
		Access2,
		Format2,
		Constness2
	> const &_view2
)
{
	mizuiro::detail::variant_apply_binary(
		algorithm::detail::unwrap_binary_both<
			Function
		>(
			_function
		),
		_view1.impl(),
		_view2.impl()
	);
}

}
}
}

#endif
