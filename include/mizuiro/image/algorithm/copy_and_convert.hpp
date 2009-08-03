#ifndef MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy_and_convert.hpp>
#include <sge/variant/apply_binary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewS,
	typename ViewD
>
void
copy_and_convert(
	ViewS const &src,
	ViewD const &dest
)
{
	sge::variant::apply_binary(
		detail::apply_binary_iteration<
			detail::copy_and_convert
		>(
			detail::copy_and_convert()
		),
		src.range(),
		dest.range()
	);
}

}
}
}

#endif
