//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_HPP_INCLUDED

#include <mizuiro/image/algorithm/binary_iteration.hpp>
#include <mizuiro/image/algorithm/make_iterator_identity.hpp>


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
	ViewS const &_source,
	ViewD const &_dest,
	Fun const &_fun
)
{
	mizuiro::image::algorithm::binary_iteration(
		_fun,
		_source,
		_dest,
		mizuiro::image::algorithm::make_iterator_identity()
	);
}

}
}
}

#endif
