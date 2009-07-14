#ifndef MIZUIRO_IMAGE_ALGORITM_FILL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITM_FILL_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_iteration.hpp>
#include <mizuiro/image/algorithm/detail/fill.hpp>
#include <sge/variant/apply_unary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewD,
	typename Color
>
void
fill(
	ViewD const &dest,
	Color const &color
)
{
	sge::variant::apply_unary(
		detail::apply_iteration<
			detail::fill<
				Color
			>
		>(
			detail::fill<
				Color
			>(
				color
			)
		),
		dest.range()
	);
}

}
}
}

#endif
