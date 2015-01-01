//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/luminance.hpp>
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/bresenham.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


namespace
{
}

int main()
{
	typedef int channel_type;

	typedef mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::color::format::homogenous_static<
			channel_type,
			mizuiro::color::layout::l
		>
	> format;

	typedef mizuiro::image::store<
		format
	> store;

	typedef store::view_type view_type;

	store::dim const dim(
		32u,
		32u
	);

	typedef
	mizuiro::color::object<
		format::color_format
	>
	color_object;

	store img{
		dim,
		color_object(
			(mizuiro::color::init::luminance() = static_cast<channel_type>(0))
		)
	};

	view_type const view(
		img.view()
	);

	color_object const color0(
		(mizuiro::color::init::luminance() = static_cast<channel_type>(10))
	);

	color_object const color1(
		(mizuiro::color::init::luminance() = static_cast<channel_type>(99))
	);

	view_type::dim const start(
		15u,
		15u
	);

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
			color0,
			color1
		);
	}

	// TODO: Make this easier
	for (view_type::dim::value_type y = 0; y < view.size()[1]; ++y)
	{
		for (view_type::dim::value_type x = 0; x < view.size()[0]; ++x)
		{
			int value = view[view_type::dim(x, y)].get(mizuiro::color::channel::luminance());
			if (value)
				std::cout << value;
			else
				std::cout << "  ";
		}
		std::cout << std::endl;
	}

}
