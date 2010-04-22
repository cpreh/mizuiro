#ifndef MIZUIRO_COLOR_DETAIL_INIT_SET_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_INIT_SET_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/detail/init_channel.hpp>
#include <mizuiro/color/detail/init_channel_percentage.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
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
			typename Color::access,
			typename Color::format,
			Channel
		>::type,
		Value
	>,
	void
>::type
init_set_channel(
	Color &color,
	init_channel<
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
init_set_channel(
	Color &color,
	init_channel_percentage<
		Value,
		Channel
	> const &init
)
{
	color. template set<
		Channel
	>(
		denormalize<
			typename Color::access,
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

#endif
