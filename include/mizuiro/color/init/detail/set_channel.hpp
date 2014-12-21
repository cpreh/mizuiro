//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_SET_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_SET_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/init/detail/channel_percentage.hpp>
#include <mizuiro/color/init/detail/channel_value.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Color,
	typename Value,
	typename Channel
>
void
set_channel(
	Color &_color,
	mizuiro::color::init::detail::channel_value<
		Value,
		Channel
	> const &_init
)
{
	static_assert(
		std::is_same<
			mizuiro::color::types::channel_value<
				typename
				Color::format,
				Channel
			>,
			Value
		>::value,
		"Channel types must match exactly for '=' initialization"
	);

	_color.set(
		_init.channel(),
		_init.value()
	);
}

template<
	typename Color,
	typename Value,
	typename Channel
>
void
set_channel(
	Color &_color,
	mizuiro::color::init::detail::channel_percentage<
		Value,
		Channel
	> const &_init
)
{
	_color.set(
		_init.channel(),
		mizuiro::color::denormalize<
			typename
			Color::format
		>(
			_color.format_store(),
			_init.channel(),
			_init.value()
		)
	);
}

}
}
}
}

#endif
