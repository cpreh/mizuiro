#ifndef MIZUIRO_COLOR_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_HAS_CHANNEL_HPP_INCLUDED

#include <boost/mpl/contains.hpp>

namespace mizuiro
{
namespace color
{
template
<
	typename Color,
	typename Channel
>
struct has_channel
:
boost::mpl::contains<
	typename Color::layout::order, 
	Channel
>
{
};
}
}

#endif
