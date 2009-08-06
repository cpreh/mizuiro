#ifndef MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_HPP_INCLUDED

#include <mizuiro/image/algorithm/transform_binary.hpp>
#include <mizuiro/image/algorithm/transform_ternary.hpp>

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
transform(
	ViewS const &source,
	ViewD const &dest,
	Fun const &fun
)
{
	transform_binary(
		source,
		dest,
		fun
	);
}

template<
	typename ViewS1,
	typename ViewS2,
	typename ViewD,
	typename Fun
>
void
transform(
	ViewS1 const &source1,
	ViewS2 const &source2,
	ViewD const &dest,
	Fun const &fun
)
{
	transform_ternary(
		source1,
		source2,
		dest,
		fun
	);
}


}
}
}

#endif
