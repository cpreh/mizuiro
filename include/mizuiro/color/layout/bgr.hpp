#ifndef MIZUIRO_COLOR_LAYOUT_BGR_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_BGR_HPP_INCLUDED

#include <mizuiro/color/layout/additive.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

typedef additive<
	boost::mpl::vector3<
		channel::blue,
		channel::green,
		channel::red
	>
> bgr;

}
}
}

#endif
