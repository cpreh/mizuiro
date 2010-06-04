#ifndef MIZUIRO_COLOR_LAYOUT_HSV_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_HSV_HPP_INCLUDED

#include <mizuiro/color/layout/cylindrical.hpp>
#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

typedef cylindrical<
	boost::mpl::vector3<
		channel::hue,
		channel::saturation,
		channel::value
	>
> hsv;

}
}
}

#endif
