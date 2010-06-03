#ifndef MIZUIRO_COLOR_IS_HSV_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_HSV_HPP_INCLUDED

#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/color/has_channel.hpp>
#include <boost/mpl/and.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Format
>
struct is_hsv
:
boost::mpl::and_
<
	has_channel
	<
		Format,
		channel::hue
	>,
	has_channel
	<
		Format,
		channel::saturation
	>,
	has_channel
	<
		Format,
		channel::value
	>
>
{
};

}
}

#endif
