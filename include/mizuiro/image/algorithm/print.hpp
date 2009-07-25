#ifndef MIZUIRO_IMAGE_ALGORITM_PRINT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITM_PRINT_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_unary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/print.hpp>
#include <sge/variant/apply_unary.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename Sink,
	typename ViewS
>
void
print(
	Sink &sink,
	ViewS const &src
)
{
	sge::variant::apply_unary(
		detail::apply_unary_iteration(
			detail::print<
				Sink
			>(
				sink
			)
		),
		src.range()
	);
}

}
}
}

#endif
