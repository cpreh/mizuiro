//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_BRESENHAM_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_BRESENHAM_HPP_INCLUDED

#include <algorithm>
#include <cmath>

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template
<
	typename View,
	typename Color
>
void
bresenham
(
	View const &v,
	typename View::dim const &start,
	typename View::dim const &end,
	Color const &c
)
{
	int x0 = static_cast<int>(start[0]);
	int y0 = static_cast<int>(start[1]);
	int x1 = static_cast<int>(end[0]);
	int y1 = static_cast<int>(end[1]);

	bool steep = std::abs(y1 - y0) > std::abs(x1 - x0);
	if (steep){
		std::swap(x0, y0);
		std::swap(x1, y1);
	}
	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	int deltax = x1 - x0;
	int deltay = std::abs(y1 - y0);
	int error = deltax / 2;
	int ystep;
	int y = y0;
	ystep = (y0 < y1) ? 1 : -1;
	for (int x = x0; x <= x1; ++x)
	{
		if (steep)
			v[typename View::dim(y, x)] = c;
		else
			v[typename View::dim(x, y)] = c;
		error -= deltay;
		if (error < 0)
		{
			y += ystep;
			error += deltax;
		}
	}
}

}
}
}

#endif
