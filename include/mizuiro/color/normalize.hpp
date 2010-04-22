#ifndef MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <mizuiro/color/channel_min.hpp>
#include <mizuiro/color/channel_max.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Channel,
	typename Float,
	typename Color
>
typename
boost::enable_if
<
	boost::is_floating_point
	<
		Float
	>,
	Float
>::type
normalize
(
	Color const &c
)
{
	typedef typename color::types::channel_value<
		typename Color::access,
		typename Color::format,
		Channel
	>::type channel_value;
						
	return 
		(
			static_cast<Float>
			(
				c.template get<Channel>()
			)
			-
			static_cast<Float>
			(
				color::channel_min
				<
					channel_value
				>()
			)
		)
		/
		(
			static_cast<Float>
			(
				color::channel_max
				<
					channel_value
				>()
			)
			-
			static_cast<Float>
			(
				color::channel_min
				<
					channel_value
				>()
			)
		);
}

}
}

#endif
