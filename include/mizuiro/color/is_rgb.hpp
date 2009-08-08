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
	typename Format
>
struct is_rgb
:
boost::mpl::and_
<
	has_channel
	<
		Format,
		channel::red
	>,
	has_channel
	<
		Format,
		channel::green
	>,
	has_channel
	<
		Format,
		channel::blue
	>
>
{
};

}
}

#endif
