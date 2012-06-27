//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous_static.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/flipped_view.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/to_pitch_view.hpp>
#include <mizuiro/image/access/interleaved.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/types/interleaved.hpp>
#include <mizuiro/image/types/interleaved_normal.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int main()
{
	typedef float channel_type;

	typedef mizuiro::image::interleaved<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::color::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	> format;

	typedef mizuiro::image::store<
		format,
		mizuiro::access::normal
	> store;

	store img(
		store::dim(
			4,
			6
		)
	);

	typedef store::view_type view_type;

	{
		view_type const view(
			img.view()
		);

		typedef view_type::dim dim;

		typedef dim::size_type size_type;

		dim const size(
			view.size()
		);

		for(size_type x = 0; x < size[0]; ++x)
			for(size_type y = 0; y < size[1]; ++y)
				view[
					dim(
						x,
						y
					)
				]
				= mizuiro::color::object<
					format::color_format
				>(
					(mizuiro::color::init::red() = static_cast<channel_type>(x))
					(mizuiro::color::init::green() = static_cast<channel_type>(y))
					(mizuiro::color::init::blue() = static_cast<channel_type>(255))
					(mizuiro::color::init::alpha() = static_cast<channel_type>(255))
				);
	}

	typedef view_type::bound_type bound_type;

	typedef mizuiro::image::to_pitch_view<
		view_type
	>::type pitch_view;

	pitch_view const sub_view(
		mizuiro::image::sub_view(
			img.view(),
			bound_type(
				bound_type::dim(
					1,
					1
				),
				bound_type::dim(
					3,
					4
				)
			)
		)
	);

	pitch_view const flipped_view(
		mizuiro::image::flipped_view(
			sub_view
		)
	);

	mizuiro::image::algorithm::print(
		std::cout,
		flipped_view
	);

	std::cout << '\n';
}
