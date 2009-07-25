#ifndef MIZUIRO_IMAGE_ALGORITM_FILL_C_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITM_FILL_C_HPP_INCLUDED

#include <mizuiro/image/algorithm/fill.hpp>
#include <boost/spirit/home/phoenix/core/value.hpp>

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
	ViewD const &dest,
	Color const &color
)
{
	fill(
		dest,
		boost::phoenix::val(
			color
		)
	);
}

}
}
}

#endif
