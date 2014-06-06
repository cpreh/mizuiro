//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_dynamic.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/color/format/dynamic_ns/static_to_dynamic_channel_fwd.hpp>
#include <mizuiro/color/format/include/homogenous_dynamic.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


namespace
{

enum class available_channels
{
	alpha,
	red,
	green,
	blue,
	mizuiro_enum_maximum = blue
};

#define MAKE_DYNAMIC_CHANNEL_INDEX(\
	channel_name \
)\
available_channels \
dynamic_channel_index( \
	mizuiro::color::channel::channel_name const &\
)\
{\
	return available_channels::channel_name;\
}

MAKE_DYNAMIC_CHANNEL_INDEX(
	alpha
)

MAKE_DYNAMIC_CHANNEL_INDEX(
	red
)

MAKE_DYNAMIC_CHANNEL_INDEX(
	green
)

MAKE_DYNAMIC_CHANNEL_INDEX(
	blue
)

}

namespace mizuiro
{
namespace color
{
namespace format
{
namespace dynamic_ns
{

template<>
struct static_to_dynamic_channel<
	available_channels
>
{
	template<
		typename StaticChannel
	>
	static
	inline
	available_channels
	execute(
		StaticChannel const &_channel
	)
	{
		return
			::dynamic_channel_index(
				_channel
			);
	}
};

}
}
}
}

int
main()
{
	typedef mizuiro::color::format::homogenous_dynamic<
		std::uint8_t,
		available_channels,
		4
	>
	color_uint8_4_format;

	color_uint8_4_format::channel_array const rgba_order =
	{{
		available_channels::red,
		available_channels::green,
		available_channels::blue,
		available_channels::alpha
	}};

	color_uint8_4_format const rgba_format(
		rgba_order
	);

	typedef
	mizuiro::color::object<
		color_uint8_4_format
	>
	color_uint8_4;

	typedef
	mizuiro::color::format::store<
		color_uint8_4_format
	>
	color_format_store;

	color_format_store const rgba_format_store(
		&rgba_format
	);

	color_uint8_4 const test1(
		(mizuiro::color::init::red() %= 0.5)
		(mizuiro::color::init::green() %= 0.2)
		(mizuiro::color::init::blue() %= 0.1)
		(mizuiro::color::init::alpha() %= 0.3),
		rgba_format_store
	);

	std::cout
		<<
		test1.get(
			available_channels::red
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
		color_uint8_4_format
	>
	image_uint8_4_format;

	typedef
	mizuiro::image::store<
		image_uint8_4_format
	>
	uint8_4_store;

	uint8_4_store store(
		uint8_4_store::dim(
			5,
			3
		),
		uint8_4_store::format_store_type(
			image_uint8_4_format(
				rgba_format_store
			)
		)
	);

	uint8_4_store::view_type const view(
		store.view()
	);

	mizuiro::image::algorithm::fill_c(
		view,
		test1
	);

	mizuiro::image::algorithm::print(
		std::cout,
		view
	);

	std::cout << '\n';
}
