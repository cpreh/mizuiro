//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/format_store.hpp>
#include <mizuiro/color/homogenous_dynamic.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/access/dynamic_channel.hpp>
#include <mizuiro/color/access/homogenous_dynamic.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_dynamic.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/access/interleaved.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/types/interleaved.hpp>
#include <mizuiro/image/types/interleaved_normal.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


namespace
{

namespace available_channels
{
enum type
{
	alpha,
	red,
	green,
	blue,
	size
};
}

namespace available_layouts
{
enum type
{
	default_
};
}

#define MAKE_DYNAMIC_CHANNEL_INDEX(\
	channel_name \
)\
available_channels::type \
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
namespace access
{

template<
	typename Format,
	typename Channel
>
struct dynamic_channel<
	Format,
	Channel,
	typename boost::enable_if<
		boost::is_same<
			typename Format::available_channels,
			available_channels::type
		>
	>::type
>
{
	static
	available_channels::type
	execute(
		mizuiro::color::format_store<Format> const &,
		Channel const &
	)
	{
		return
			::dynamic_channel_index(
				Channel()
			);
	}
};

}
}
}

int main()
{
	typedef mizuiro::color::homogenous_dynamic<
		boost::uint8_t,
		available_channels::type,
		available_channels::size,
		available_layouts::type,
		4
	> color_uint8_4_format;

	color_uint8_4_format::channel_array const rgba_order =
	{{
		available_channels::red,
		available_channels::green,
		available_channels::blue,
		available_channels::alpha
	}};

	color_uint8_4_format const rgba_format(
		rgba_order,
		available_layouts::default_
	);

	typedef mizuiro::color::object<
		color_uint8_4_format
	> color_uint8_4;

	typedef mizuiro::color::format_store<
		color_uint8_4_format
	> color_format_store;

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

	typedef mizuiro::image::interleaved<
		mizuiro::image::dimension<
			2
		>,
		color_uint8_4_format
	> image_uint8_4_format;

	typedef mizuiro::image::store<
		image_uint8_4_format,
		mizuiro::access::normal
	> uint8_4_store;

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
