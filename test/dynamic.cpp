//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/format/homogenous_dynamic.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/color/format/include/homogenous_dynamic.hpp>
#include <mizuiro/color/format/dynamic_ns/static_to_dynamic_channel.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <cstdint>
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
	return \
		available_channels::channel_name;\
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

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	dynamic_heterogenous
)
{
MIZUIRO_DETAIL_POP_WARNING

	typedef
	mizuiro::color::format::homogenous_dynamic<
		std::uint8_t,
		available_channels,
		4
	>
	color_uint8_4_format;

	color_uint8_4_format::channel_array const rgba_order{{
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
		(
			mizuiro::color::init::red() = static_cast<std::uint8_t>(4)
		)(
			mizuiro::color::init::green() = static_cast<std::uint8_t>(10)
		)(
			mizuiro::color::init::blue() = static_cast<std::uint8_t>(20)
		)(
			mizuiro::color::init::alpha() = static_cast<std::uint8_t>(45)
		)
		,
		rgba_format_store
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::red()
		)
		==
		static_cast<std::uint8_t>(4)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::green()
		)
		==
		static_cast<std::uint8_t>(10)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::blue()
		)
		==
		static_cast<std::uint8_t>(20)
	);

	BOOST_CHECK(
		test1.get(
			mizuiro::color::channel::alpha()
		)
		==
		static_cast<std::uint8_t>(45)
	);
}
