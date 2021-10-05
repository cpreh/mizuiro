//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/flipped_view.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/to_pitch_view.hpp>
#include <mizuiro/image/algorithm/fill_indexed.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


int
main()
{
	using
	channel_type
	=
	float;

	using
	format
	=
	mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::color::format::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	>;

	using
	store
	=
	mizuiro::image::store<
		format
	>;

	using
	view_type
	=
	store::view_type;

	store img{
		store::dim(
			4U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			6U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		),
		[](
			view_type const &_view
		)
		{
			mizuiro::image::algorithm::fill_indexed(
				_view,
				[](
					view_type::dim const _index
				)
				{
					return
						mizuiro::color::object<
							format::color_format
						>(
							(mizuiro::color::init::red()
								= static_cast<channel_type>(_index.at_c<0>()))
							(mizuiro::color::init::green()
								= static_cast<channel_type>(_index.at_c<1>()))
							(mizuiro::color::init::blue() = channel_type{255}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
							(mizuiro::color::init::alpha() = channel_type{255}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
						);
				},
				mizuiro::image::algorithm::uninitialized::yes
			);
		}
	};

	using
	bound_type
	=
	view_type::bound_type;

	using
	pitch_view
	=
	mizuiro::image::to_pitch_view<
		view_type
	>;

	pitch_view const sub_view(
		mizuiro::image::sub_view(
			img.view(),
			bound_type(
				bound_type::pos_t(
					bound_type::dim(
						1U,
						1U
					)
				),
				bound_type::size_t(
					bound_type::dim(
						3U,
						4U
					)
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
