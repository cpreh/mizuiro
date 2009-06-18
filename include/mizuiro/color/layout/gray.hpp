#ifndef MIZUIRO_COLOR_LAYOUT_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_GRAY_HPP_INCLUDED

#include <mizuiro/color/channel/gray.hpp>
#include <boost/mpl/vector.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

struct gray {
	typedef boost::mpl::vector<
		channel::gray
	> order;
};

}
}
}

#endif
