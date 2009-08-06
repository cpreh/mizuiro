#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_TERNARY_ITERATION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_APPLY_TERNARY_ITERATION_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_ternary_iteration_fun.hpp>

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
apply_ternary_iteration_fun<
	Function
> const
apply_ternary_iteration(
	Function const &fun
)
{
	return apply_ternary_iteration_fun<
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
