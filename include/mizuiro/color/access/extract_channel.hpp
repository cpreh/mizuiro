#ifndef MIZUIRO_COLOR_ACCESS_EXTRACT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_EXTRACT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Channel,
	typename Constness
>
typename boost::disable_if<
	boost::true_type,
	typename types::channel_reference<
		Access,
		Format,
		Channel,
		Constness
	>::type
>::type
extract_channel(
	typename types::pointer<
		Access,
		Format,
		Constness
	>::type
);

}
}
}

#endif
