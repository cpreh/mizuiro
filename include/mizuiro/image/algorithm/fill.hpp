//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_FILL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FILL_HPP_INCLUDED

#include <mizuiro/image/algorithm/unary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/fill.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewD,
	typename Fun
>
void
fill(
	ViewD const &_dest,
	Fun const &_fun
)
{
	algorithm::unary_iteration(
		detail::fill<
			Fun
		>(
			_fun
		),
		_dest
	);
}

}
}
}

#endif
