//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/bound.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/copy.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <iterator>
#include <iostream>
#include <ostream>

#include <mizuiro/access/raw.hpp>
#include <mizuiro/image/raw_view.hpp>

int main()
{
	typedef float channel_type;

	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			3
		>,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous_static<
				channel_type,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	typedef mizuiro::image::store<
		format,
		mizuiro::access::raw
	> store;

	store img(
		store::dim_type(
			100,
			100,
			100	
		)
	);

	typedef store::view_type view_type;

	typedef view_type::bound_type bound_type;

	// TODO: create an algorithm for this!
	{
		view_type const view(
			img.view()
		);

		typedef view_type::dim_type dim_type;

		typedef dim_type::size_type size_type;

		dim_type const dim(
			img.view().dim()
		);

		for(size_type x = 0; x < dim[0]; ++x)
			for(size_type y = 0; y < dim[1]; ++y)
				for(size_type z = 0; z < dim[2]; ++z)
					view[
						dim_type(
							x,
							y,
							z
						)
					]
					= mizuiro::color::object<
						format::color_format
					>(
						(mizuiro::color::init::red = static_cast<channel_type>(x))
						(mizuiro::color::init::green = static_cast<channel_type>(y))
						(mizuiro::color::init::blue = static_cast<channel_type>(z))
						(mizuiro::color::init::alpha = static_cast<channel_type>(255))
					);
	}

	std::cout << '\n';

	view_type const sub_view(
		mizuiro::image::sub_view(
			img.view(),
			bound_type(
				bound_type::dim_type(
					1,
					1,
					1
				),
				bound_type::dim_type(
					3,
					4,
					3	
				)
			)
		)
	);

	std::cout
		<< "sub image (with pitch "
		<< sub_view.pitch()
		<< ")\n";


	view_type const sub_sub_view(
		mizuiro::image::sub_view(
			sub_view,
			bound_type(
				bound_type::dim_type(
					1,	
					1,
					1
				),
				bound_type::dim_type(
					2,
					3,
					2
				)
			)
		)
	);

	std::cout
		<< "sub sub image (with pitch "
		<< sub_sub_view.pitch()
		<< ")\n";

	mizuiro::image::algorithm::print(
		std::cout,
		sub_sub_view
	);

	std::cout << '\n';

	{
		typedef std::reverse_iterator<
			view_type::iterator
		> reverse_iterator;

		for(
			reverse_iterator it(
				sub_sub_view.end()
			);
			it != reverse_iterator(sub_sub_view.begin());
			++it
		)
			std::cout << *it << ' ';
	}

	std::cout << '\n';
}
