#ifndef MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_unary_iteration.hpp>
#include <sge/variant/apply_unary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename View,
	typename Fun
>
Fun const
for_each(
	View const &view,
	Fun const &fun
)
{
	sge::variant::apply_unary(
		detail::apply_unary_iteration(
			fun
		),
		view.range()
	);

	return fun;
}

}
}
}

#endif
