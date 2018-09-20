//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_dynamic.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/color/format/include/homogenous_dynamic.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgb.hpp>
#include <mizuiro/color/space/rgb.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <functional>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef mizuiro::color::format::homogenous_dynamic<
		std::uint8_t,
		mizuiro::color::space::rgb,
		3
	>
	color_uint8_3_format;

	color_uint8_3_format const rgb_format{
		mizuiro::color::layout::rgb{}
	};

	typedef
	mizuiro::color::object<
		color_uint8_3_format
	>
	color_uint8_3;

	typedef
	mizuiro::color::format::store<
		color_uint8_3_format
	>
	color_format_store;

	color_format_store const rgb_format_store(
		std::cref(
			rgb_format
		)
	);

	color_uint8_3 const test1(
		(mizuiro::color::init::red() %= 0.5)
		(mizuiro::color::init::green() %= 0.2)
		(mizuiro::color::init::blue() %= 0.1),
		rgb_format_store
	);

	std::cout
		<<
		test1.get(
			mizuiro::color::channel::red()
		)
		<< '\n';

	std::cout
		<< test1
		<< '\n';

	typedef
	mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			2
		>,
		color_uint8_3_format
	>
	image_uint8_3_format;

	typedef
	mizuiro::image::store<
		image_uint8_3_format
	>
	uint8_3_store;

	uint8_3_store const store(
		uint8_3_store::dim(
			5u,
			3u
		),
		test1,
		uint8_3_store::format_store_type(
			image_uint8_3_format{
				rgb_format_store
			}
		)
	);

	mizuiro::image::algorithm::print(
		std::cout,
		store.view()
	);

	std::cout << '\n';
}
