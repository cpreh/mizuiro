#ifndef MIZUIRO_IMAGE_ALGORITHM_FILL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FILL_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_unary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/fill.hpp>
#include <mizuiro/detail/variant_apply_unary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewD,
	typename Fun
>
void
fill(
	ViewD const &dest,
	Fun const &fun
)
{
	mizuiro::detail::variant_apply_unary(
		detail::apply_unary_iteration(
			detail::fill<
				Fun	
			>(
				fun	
			)
		),
		dest.range()
	);
}

}
}
}

#endif
