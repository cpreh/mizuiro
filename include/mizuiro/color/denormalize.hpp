#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/denormalize.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Format,
	typename Channel,
	typename Float
>
typename boost::enable_if
<
	boost::is_floating_point
	<
		Float
	>,
	typename 
	types::channel_value
	<
		Format,
		Channel
	>::type
>::type
denormalize
(
	Float const src
)
{
	return
		::mizuiro::denormalize<
			typename types::channel_value
			<
				Format,
				Channel
			>::type
		>(
			src
		);
}

}
}

#endif
