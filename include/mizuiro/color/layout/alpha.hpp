#ifndef MIZUIRO_COLOR_LAYOUT_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_ALPHA_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <boost/mpl/vector/vector10.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

struct alpha {
	typedef boost::mpl::vector1<
		channel::alpha
	> order;
};

}
}
}

#endif
