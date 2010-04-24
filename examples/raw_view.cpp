#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/is_raw_view.hpp>
#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <fcppt/tr1/array.hpp>
#include <algorithm>
#include <iostream>
#include <ostream>

int main()
{
	typedef mizuiro::image::dimension<
		2
	> dim_type;

	typedef mizuiro::image::format<
		dim_type,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous<
				float,
				mizuiro::color::layout::rgba
			>
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

	typedef std::tr1::array<
		mizuiro::raw_value,
		width * height * channel_bytes * element_count
	> raw_array;

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

	typedef mizuiro::image::view<
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
		view
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
