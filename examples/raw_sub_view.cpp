//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/array.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/access/homogenous_raw.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int main()
{
	typedef float channel_type;

	typedef mizuiro::image::dimension<
		3
	> dim;

	typedef mizuiro::image::format<
		dim,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous_static<
				channel_type,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	mizuiro::size_type const
		width(
			4
		),
		height(
			4
		),
		depth(
			4
		);

	mizuiro::array<
		unsigned char,
		width
		* height
		* depth
		* sizeof(float)
		* format::color_format::element_count
	>::type raw_data;

	typedef mizuiro::image::pitch_view<
		mizuiro::access::raw,
		format,
		mizuiro::nonconst_tag
	> view_type;

	typedef view_type::bound_type bound_type;

	view_type const view(
		mizuiro::image::make_raw_view<
			format
		>(
			raw_data.data(),
			dim(
				width,
				height,
				depth
			),
			view_type::pitch_type::null()
		)
	);

	{
		typedef dim::size_type size_type;

		dim const size(
			view.size()
		);

		for(size_type x = 0; x < size[0]; ++x)
			for(size_type y = 0; y < size[1]; ++y)
				for(size_type z = 0; z < size[2]; ++z)
					view[
						dim(
							x,
							y,
							z
						)
					]
					= mizuiro::color::object<
						format::color_format
					>(
						(mizuiro::color::init::red() = static_cast<channel_type>(x))
						(mizuiro::color::init::green() = static_cast<channel_type>(y))
						(mizuiro::color::init::blue() = static_cast<channel_type>(z))
						(mizuiro::color::init::alpha() = static_cast<channel_type>(255))
					);
	}

	view_type const sub_view(
		mizuiro::image::sub_view(
			view,
			bound_type(
				bound_type::dim(
					1,
					1,
					0
				),
				bound_type::dim(
					2,
					3,
					2
				)
			)
		)
	);

	std::cout
		<< "sub_view.pitch(): "
		<< sub_view.pitch()
		<< '\n';

	mizuiro::image::algorithm::print(
		std::cout,
		sub_view
	);

	std::cout << '\n';
}
