#ifndef MIZUIRO_IMAGE_ALGORITM_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITM_COPY_AND_CONVERT_HPP_INCLUDED

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
	typename ViewD,
	typename ViewS
>
void
copy_and_convert(
	ViewD const &dest,
	ViewS const &src
)
{
	sge::variant::apply_binary(
		detail::apply_binary_iteration<
			detail::copy_and_convert
		>(
			detail::copy_and_convert()
		),
		dest.range(),
		src.range()
	);
}

}
}
}

#endif
