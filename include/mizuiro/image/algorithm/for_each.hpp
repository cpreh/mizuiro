//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_unary_iteration.hpp>
#include <mizuiro/detail/variant_apply_unary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename View,
	typename Fun
>
Fun const
for_each(
	View const &view,
	Fun const &fun
)
{
	mizuiro::detail::variant_apply_unary(
		detail::apply_unary_iteration(
			fun
		),
		view.range()
	);

	return fun;
}

}
}
}

#endif
