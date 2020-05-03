//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/size_list.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/format/heterogenous_static.hpp>
#include <mizuiro/color/format/include/heterogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/luminance.hpp>
#include <mizuiro/color/layout/la.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_heterogenous.hpp>
#include <fcppt/config/external_begin.hpp>
#include <catch2/catch.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


TEST_CASE(
	"prepare store",
	"[mizuiro]"
)
{
	using
	luminance24_alpha8_format
	=
	mizuiro::color::format::heterogenous_static<
		mizuiro::size_list<
			24U, // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			8U // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		>,
		mizuiro::color::layout::la
	>;

	using
	luminance24_alpha8_color
	=
	mizuiro::color::object<
		luminance24_alpha8_format
	>;

	using
	image_format
	=
	mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			2
		>,
		luminance24_alpha8_format
	>;

	using
	store_type
	=
	mizuiro::image::store<
		image_format
	>;

	store_type const store(
		store_type::dim{
			1U,
			1U
		},
		[](
			store_type::view_type const &_view
		)
		{
			mizuiro::image::algorithm::fill_c(
				_view,
				luminance24_alpha8_color(
					(mizuiro::color::init::luminance() = std::uint32_t{0x1E1FF}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
					(mizuiro::color::init::alpha() = std::uint8_t{0xF}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
				),
				mizuiro::image::algorithm::uninitialized::yes
			);
		}
	);

	CHECK(
		store.view()[
			store_type::dim(
				0U,
				0U
			)
		].get(
			mizuiro::color::channel::luminance()
		)
		==
		std::uint32_t{0x1E1FF} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);

	CHECK(
		store.view()[
			store_type::dim(
				0U,
				0U
			)
		].get(
			mizuiro::color::channel::alpha()
		)
		==
		std::uint8_t{0xF} // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
	);
}
