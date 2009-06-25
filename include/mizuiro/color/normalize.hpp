#ifndef MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace mizuiro
{
namespace color
{
template
<
	typename Color,
	typename Channel,
	typename Float
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
	return 
		(
			static_cast<Float>
			(
				c.template get<Channel>()
			)
			-
			static_cast<Float>
			(
				Color::layout::template channel_min
				<
					Channel
				>()
			)
		)
		/
		(
			static_cast<Float>
			(
				Color::layout::template channel_max
				<
					Channel
				>()
			)
			-
			static_cast<Float>
			(
				Color::layout::template channel_min
				<
					Channel
				>()
			)
		);
}
}
}

#endif
