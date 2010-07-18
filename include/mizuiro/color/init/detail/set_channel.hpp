//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_SET_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_SET_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/init/detail/channel.hpp>
#include <mizuiro/color/init/detail/channel_percentage.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

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
typename boost::enable_if<
	boost::is_same<
		typename color::types::channel_value<
			typename Color::format,
			Channel
		>::type,
		Value
	>,
	void
>::type
set_channel(
	Color &color,
	detail::channel<
		Value,
		Channel
	> const &init
)
{
	color. template set<
		Channel
	>(
		init.value()
	);
}

template<
	typename Color,
	typename Value,
	typename Channel
>
void
set_channel(
	Color &color,
	detail::channel_percentage<
		Value,
		Channel
	> const &init
)
{
	color. template set<
		Channel
	>(
		denormalize<
			typename Color::format,
			Channel
		>(
			init.value()
		)
	);
}

}
}
}
}

#endif
