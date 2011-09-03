//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_FILL_C_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_FILL_C_HPP_INCLUDED

#include <mizuiro/image/algorithm/fill.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/spirit/home/phoenix/core/value.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewD,
	typename Color
>
void
fill_c(
	ViewD const &_dest,
	Color const &_color
)
{
	algorithm::fill(
		_dest,
		boost::phoenix::val(
			_color
		)
	);
}

}
}
}

#endif
