#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_MAX_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_MAX_ALPHA_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <mizuiro/color/channel/alpha.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{
template
<
	class Color
>
typename 
boost::disable_if
<
	has_channel
	<
		typename Color::layout,
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
		typename Color::layout,
		channel::alpha
	>, 
	void
>::type 
max_alpha(
	Color &c)
{
	c.template set
	<
		channel::alpha
	>
	(
		Color::layout::template channel_max
		<
			channel::alpha
		>()
	);
}

}
}
}

#endif
