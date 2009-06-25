#ifndef MIZUIRO_COLOR_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_HAS_CHANNEL_HPP_INCLUDED

#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/end.hpp>

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
boost::is_same
<
	typename boost::mpl::find
	<
		typename Color::layout::order, 
		Channel
	>::type, 
	typename boost::mpl::end
	<
		typename Color::layout::order
	>::type
>
{
};
}
}

#endif
