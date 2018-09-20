//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/const_view.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
	typedef
	mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			3
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

	typedef
	store::view_type
	view_type;

	store const img{
		store::dim(
			3u,
			2u,
			1u
		),
		[](
			view_type const &_view
		)
		{
			for(
				auto color
				:
				_view
			)
			{
				color.set(
					mizuiro::color::channel::red(),
					std::uint8_t{10}
				);
			}
		}
	};

	typedef
	mizuiro::image::const_view<
		view_type
	>
	const_view_type;

	const_view_type const_view(
		img.view()
	);

	for(
		auto const &color
		:
		const_view
	)
		std::cout
			<<
			static_cast<
				int
			>(
				color.get(
					mizuiro::color::channel::red()
				)
			)
			<< ' ';

	std::cout << '\n';
}
