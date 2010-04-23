#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_MAX_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_MAX_ALPHA_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/has_channel.hpp>
#include <mizuiro/color/channel_max.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

// TODO: what is this doing here?
template
<
	class Color
>
typename 
boost::disable_if
<
	has_channel
	<
		typename Color::format,
		channel::alpha
	>, 
	void
>::type 
max_alpha(Color &)
{
}

template
<
	class Color
>
typename 
boost::enable_if
<
	has_channel
	<
		typename Color::format,
		channel::alpha
	>, 
	void
>::type 
max_alpha(
	Color &c
)
{
	c.template set
	<
		channel::alpha
	>
	(
		color::channel_max<
			typename color::types::channel_value<
				typename Color::access,
				typename Color::format,
				channel::alpha
			>::type
		>()
	);
}

}
}
}

#endif
