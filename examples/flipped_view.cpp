//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/flipped_view.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <iostream>
#include <ostream>

int main()
{
	typedef float channel_type;

	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous<
				channel_type,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	typedef mizuiro::image::store<
		format
	> store;

	store img(
		store::dim_type(
			4,
			6
		)
	);

	typedef store::view_type view_type;

	{
		view_type const view(
			img.view()
		);

		typedef view_type::dim_type dim_type;

		typedef dim_type::size_type size_type;

		dim_type const dim(
			view.dim()
		);

		for(size_type x = 0; x < dim[0]; ++x)
			for(size_type y = 0; y < dim[1]; ++y)
				view[
					dim_type(
						x,
						y
					)
				]
				= mizuiro::color::object<
					format::color_format
				>(
					(mizuiro::color::init::red = static_cast<channel_type>(x))
					(mizuiro::color::init::green = static_cast<channel_type>(y))
					(mizuiro::color::init::blue = static_cast<channel_type>(255))
					(mizuiro::color::init::alpha = static_cast<channel_type>(255))
				);
	}

	typedef view_type::bound_type bound_type;

	view_type const sub_view(
		mizuiro::image::sub_view(
			img.view(),
			bound_type(
				bound_type::dim_type(
					1,
					1
				),
				bound_type::dim_type(
					3,
					4
				)
			)
		)
	);

	view_type const flipped_view(
		mizuiro::image::flipped_view(
			sub_view
		)
	);

	view_type::iterator it(
		flipped_view.begin()
	);

	for(
		unsigned i = 0;
		i < 3 * 4 + 1;
		++i
	)
		std::cout << *it++ << ' ';
	
	std::cout << '\n';
	std::cout << *flipped_view.end() << '\n';
	/*
	mizuiro::image::algorithm::print(
		std::cout,
		flipped_view
	);
	*/

	std::cout << '\n';
}
