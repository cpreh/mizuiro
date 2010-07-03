//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_BINARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_BINARY_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/transform_binary.hpp>
#include <mizuiro/detail/variant_apply_binary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewS,
	typename ViewD,
	typename Fun
>
void
transform_binary(
	ViewS const &source,
	ViewD const &dest,
	Fun const &fun
)
{
	mizuiro::detail::variant_apply_binary(
		detail::apply_binary_iteration(
			detail::transform_binary<
				Fun
			>(
				fun
			)
		),
		source.range(),
		dest.range()
	);
}

}
}
}

#endif
