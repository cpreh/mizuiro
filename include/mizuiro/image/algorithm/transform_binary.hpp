#ifndef MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_BINARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_BINARY_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/transform_binary.hpp>
#include <sge/variant/apply_binary.hpp>

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
	sge::variant::apply_binary(
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
