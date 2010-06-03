#ifndef MIZUIRO_COLOR_LAYOUT_HSVA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_HSVA_HPP_INCLUDED

#include <mizuiro/color/layout/cylindrical.hpp>
#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

typedef cylindrical<
	boost::mpl::vector4<
		channel::hue,
		channel::saturation,
		channel::value,
		channel::alpha
	>
> hsva;

}
}
}

#endif
