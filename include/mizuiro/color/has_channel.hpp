#ifndef MIZUIRO_COLOR_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_HAS_CHANNEL_HPP_INCLUDED

#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/end.hpp>

namespace mizuiro
{
namespace color
{
struct has_channel
:
boost::is_same
<
	typename mpl::find
	<
		typename Layout::order, 
		channel
	>::type, 
	typename mpl::end
	<
		typename Layout::order
	>::type
>
{
};
}
}

#endif
