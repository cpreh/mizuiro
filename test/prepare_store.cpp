//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/format/heterogenous_static.hpp>
#include <mizuiro/color/format/include/heterogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/luminance.hpp>
#include <mizuiro/color/layout/la.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_heterogenous.hpp>
#include <mizuiro/mpl/size_list.hpp>
#include <mizuiro/test/external_begin.hpp>
#include <mizuiro/test/external_end.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
#include <mizuiro/detail/external_end.hpp>


MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	prepare_store
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef
	mizuiro::color::format::heterogenous_static<
		mizuiro::mpl::size_list<
			24u,
			8u
		>,
		mizuiro::color::layout::la
	>
	luminance24_alpha8_format;

	typedef
	mizuiro::color::object<
		luminance24_alpha8_format
	>
	luminance24_alpha8_color;

	typedef
	mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			2
		>,
		luminance24_alpha8_format
	>
	image_format;

	typedef
	mizuiro::image::store<
		image_format
	>
	store_type;

	store_type const store(
		store_type::dim{
			1u,
			1u
		},
		[](
			store_type::view_type const &_view
		)
		{
			mizuiro::image::algorithm::fill_c(
				_view,
				luminance24_alpha8_color(
					(mizuiro::color::init::luminance() = std::uint32_t{0x1E1FF})
					(mizuiro::color::init::alpha() = std::uint8_t{0xF})
				),
				mizuiro::image::algorithm::uninitialized::yes
			);
		}
	);

	BOOST_CHECK_EQUAL(
		store.view()[
			store_type::dim(
				0u,
				0u
			)
		].get(
			mizuiro::color::channel::luminance()
		),
		std::uint32_t{0x1E1FF}
	);

	BOOST_CHECK_EQUAL(
		store.view()[
			store_type::dim(
				0u,
				0u
			)
		].get(
			mizuiro::color::channel::alpha()
		),
		std::uint8_t{0xF}
	);
}
