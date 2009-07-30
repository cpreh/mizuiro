#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy.hpp>
#include <sge/variant/apply_binary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewD,
	typename ViewS
>
void
copy(
	ViewD const &dest,
	ViewS const &src
)
{
	sge::variant::apply_binary(
		detail::apply_binary_iteration<
			detail::copy
		>(),
		dest.range(),
		src.range()
	);
}

}
}
}

#endif
