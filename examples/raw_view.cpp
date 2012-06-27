//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/array.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/access/homogenous_static.hpp>
#include <mizuiro/color/access/homogenous_raw.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous_raw.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/is_raw_view.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/access/interleaved.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/types/interleaved.hpp>
#include <mizuiro/image/types/interleaved_raw.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <algorithm>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int main()
{
	typedef mizuiro::image::dimension<
		2
	> dim_type;

	typedef mizuiro::image::interleaved<
		dim_type,
		mizuiro::color::homogenous_static<
			float,
			mizuiro::color::layout::rgba
		>
	> format;

	mizuiro::size_type const
		width(
			3
		),
		height(
			5
		),
		channel_bytes(
			sizeof(float)
		),
		element_count(
			format::color_format::element_count
		);

	typedef mizuiro::array<
		mizuiro::raw_value,
		width * height * channel_bytes * element_count
	>::type raw_array;

	raw_array raw_data = {{ 0 }};

	{
		float const test = 0.5f;

		unsigned char const *raw(
			reinterpret_cast<
				unsigned char const *
			>(
				&test
			)
		);

		for(
			raw_array::iterator dest(
				raw_data.begin()
			);
			dest != raw_data.end();
			dest += channel_bytes
		)
			std::copy(
				raw,
				raw + channel_bytes,
				dest
			);
	}

	typedef mizuiro::image::pitch_view<
		mizuiro::access::raw,
		format,
		mizuiro::nonconst_tag
	> view_type;

	view_type const view(
		mizuiro::image::make_raw_view<
			format
		>(
			raw_data.data(),
			dim_type(
				width,
				height
			),
			view_type::pitch_type::null()
		)
	);

	mizuiro::image::algorithm::copy_and_convert(
		mizuiro::image::make_const_view(
			view
		),
		view,
		mizuiro::image::algorithm::may_overlap::yes
	);

	std::cout
		<< std::boolalpha
		<< mizuiro::image::is_raw_view<
			view_type
		>::value
		<< '\n';

	mizuiro::image::algorithm::print(
		std::cout,
		view
	);

	std::cout
		<< '\n';
}
