#ifndef MIZUIRO_COLOR_IS_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_RGB_HPP_INCLUDED

#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/has_channel.hpp>
#include <boost/mpl/and.hpp>

namespace mizuiro
{
namespace color
{
template
<
	class Color
>
struct is_rgb
:
boost::mpl::and_
<
	boost::mpl::and_
	<
		has_channel
		<
			typename Color::layout,
			channel::red
		>,
		has_channel
		<
			typename Color::layout,
			channel::green
		>
	>,
	has_channel
	<
		typename Color::layout,
		channel::blue
	>
>
{
};
}
}

#endif
