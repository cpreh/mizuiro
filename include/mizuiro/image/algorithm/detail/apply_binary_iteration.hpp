#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_BINARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_BINARY_ITERATION_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration_fun.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Function
>
apply_binary_iteration_fun<
	Function
> const
apply_binary_iteration(
	Function const &fun
)
{
	return apply_binary_iteration_fun<
		Function
	>(
		fun
	);
}

}
}
}
}

#endif
