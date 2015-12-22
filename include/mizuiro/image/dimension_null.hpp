//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DIMENSION_NULL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_NULL_HPP_INCLUDED

#include <mizuiro/no_init.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename Dim
>
Dim
dimension_null()
{
	Dim ret{
		mizuiro::no_init{}
	};

	for(
		auto &elem
		:
		ret
	)
		elem = 0;

	return
		ret;
}

}
}

#endif
