//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/default_init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format/planar.hpp>
#include <mizuiro/image/format/include/planar.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	mizuiro::image::format::planar<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::color::format::homogenous_static<
			std::uint8_t,
			mizuiro::color::layout::rgba
		>
	>
	format;

	typedef
	mizuiro::image::store<
		format
	>
	store;

	store const img{
		store::dim{
			3u,
			2u
		},
		store::value_type(
			mizuiro::default_init()
		)
	};

	for(
		auto const color
		:
		img.view()
	)
		std::cout << color << ' ';

	std::cout << '\n';
}
