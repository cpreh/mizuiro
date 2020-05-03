//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/dimension_null.hpp>
#include <mizuiro/image/is_raw_view.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/cast/to_char_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <array>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
	using
	dim_type
	=
	mizuiro::image::dimension<
		2
	>;

	using
	format
	=
	mizuiro::image::format::interleaved<
		dim_type,
		mizuiro::color::format::homogenous_static<
			float,
			mizuiro::color::layout::rgba
		>
	>;

	constexpr mizuiro::size_type const width{
		3
	};

	constexpr mizuiro::size_type const height{
		5
	};

	constexpr mizuiro::size_type const channel_bytes{
		sizeof(float)
	};

	constexpr mizuiro::size_type const element_count{
		format::color_format::element_count
	};

	using
	raw_array
	=
	std::array<
		mizuiro::raw_value,
		width * height * channel_bytes * element_count
	>;

	raw_array raw_data = {{ 0 }};

	{
		float const test{0.5F}; // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)

		auto const* const raw(
			fcppt::cast::to_char_ptr<
				unsigned char const *
			>(
				&test
			)
		);

		for(
			auto *dest(
				raw_data.begin()
			);
			dest != raw_data.end();
			dest += channel_bytes // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
		)
		{
			std::copy(
				raw,
				raw + channel_bytes, // NOLINT(cppcoreguidelines-pro-bounds-pointer-arithmetic)
				dest
			);
		}
	}

	using
	view_type
	=
	mizuiro::image::pitch_view<
		mizuiro::access::raw,
		format,
		mizuiro::nonconst_tag
	>;

	view_type const view(
		mizuiro::image::make_raw_view<
			format
		>(
			raw_data.data(),
			dim_type(
				width,
				height
			),
			mizuiro::image::dimension_null<
				view_type::pitch_type
			>()
		)
	);

	mizuiro::image::algorithm::copy_and_convert<
		mizuiro::color::convert_static::converter
	>(
		mizuiro::image::make_const_view(
			view
		),
		view,
		mizuiro::image::algorithm::may_overlap::yes,
		mizuiro::image::algorithm::uninitialized::no
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
