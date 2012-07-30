//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/homogenous_static.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous_static.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/access/interleaved.hpp>
#include <mizuiro/image/algorithm/bresenham.hpp>
#include <mizuiro/image/types/interleaved.hpp>
#include <mizuiro/image/types/interleaved_normal.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <cmath>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


namespace
{
}

int main()
{
	typedef int channel_type;

	typedef mizuiro::image::interleaved<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::color::homogenous_static<
			int,
			mizuiro::color::layout::gray
		>
	> format;

	typedef mizuiro::image::store<
		format,
		mizuiro::access::normal
	> store;

	typedef store::view_type view_type;

	store::dim const dim(
		32,
		32
	);

	store img(
		dim
	);

	view_type view(
		img.view()
	);

	mizuiro::color::object<format::color_format> color =
		mizuiro::color::object<
			format::color_format
		>(
			(mizuiro::color::init::luminance() = static_cast<channel_type>(42))
		);

	view_type::dim start(15,15);

	for (int angle = 0; angle < 360; angle += 15)
	{

		double const pi = 3.1415926;
		mizuiro::image::algorithm::bresenham
		(
			view,
			start,
			view_type::dim(
				static_cast<view_type::dim::value_type>(15 + static_cast<int>(15 * std::cos(angle / 180.0 * pi))),
				static_cast<view_type::dim::value_type>(15 + static_cast<int>(15 * std::sin(angle / 180.0 * pi)))),
			color
		);
	}

	for (view_type::dim::value_type y = 0; y < view.size()[1]; ++y)
	{
		for (view_type::dim::value_type x = 0; x < view.size()[0]; ++x)
		{
			std::cout << (view[view_type::dim(x, y)].get(mizuiro::color::channel::luminance()) ? "[]" : "  ");
		}
		std::cout << std::endl;
	}

}
