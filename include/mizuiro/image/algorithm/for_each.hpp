#ifndef MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FOR_EACH_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_iteration.hpp>
#include <sge/variant/apply_binary.hpp>

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
	sge::variant::apply_binary(
		detail::apply_iteration<
			Fun
		>(
			fun
		),
		view.begin().internal(),
		view.end().internal()
	);

	return fun;
}

}
}
}

#endif
