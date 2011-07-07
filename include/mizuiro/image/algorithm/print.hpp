//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_PRINT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_PRINT_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_unary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/print.hpp>
#include <mizuiro/detail/variant_apply_unary.hpp>

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
	Sink &_sink,
	ViewS const &_src
)
{
	mizuiro::detail::variant_apply_unary(
		detail::apply_unary_iteration(
			detail::print<
				Sink
			>(
				_sink
			)
		),
		_src.range()
	);
}

}
}
}

#endif
