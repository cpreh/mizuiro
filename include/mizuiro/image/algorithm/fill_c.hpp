//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_FILL_C_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FILL_C_HPP_INCLUDED

#include <mizuiro/image/algorithm/fill.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewD,
	typename Value
>
void
fill_c(
	ViewD const &_dest,
	Value const &_value
)
{
	mizuiro::image::algorithm::fill(
		_dest,
		[
			&_value
		]
		{
			return
				_value;
		}
	);
}

}
}
}

#endif
