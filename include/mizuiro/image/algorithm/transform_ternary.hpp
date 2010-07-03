//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_TERNARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_TERNARY_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_ternary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/transform_ternary.hpp>
#include <mizuiro/detail/variant_apply_ternary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewS1,
	typename ViewS2,
	typename ViewD,
	typename Fun
>
void
transform_ternary(
	ViewS1 const &source1,
	ViewS2 const &source2,
	ViewD const &dest,
	Fun const &fun
)
{
	mizuiro::detail::variant_apply_ternary(
		detail::apply_ternary_iteration(
			detail::transform_ternary<
				Fun
			>(
				fun
			)
		),
		source1.range(),
		source2.range(),
		dest.range()
	);
}

}
}
}

#endif
