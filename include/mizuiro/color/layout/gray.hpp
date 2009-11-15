#ifndef MIZUIRO_COLOR_LAYOUT_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_GRAY_HPP_INCLUDED

#include <mizuiro/color/channel/gray.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

struct gray {
	typedef boost::mpl::vector1<
		channel::gray
	> order;
};

}
}
}

#endif
