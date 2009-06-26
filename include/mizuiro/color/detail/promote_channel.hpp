#ifndef MIZUIRO_COLOR_DETAIL_PROMOTE_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_PROMOTE_CHANNEL_HPP_INCLUDED

#include <boost/type_traits/promote.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename T
>
struct promote_channel
:
boost::promote<
	T
>
{};

}
}
}

#endif
