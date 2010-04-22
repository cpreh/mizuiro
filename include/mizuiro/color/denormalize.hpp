#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/channel_min.hpp>
#include <mizuiro/color/channel_max.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Access,
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
		Access,
		Format,
		Channel
	>::type
>::type
denormalize
(
	Float const f
)
{
	typedef 
		typename
		types::channel_value
		<
			Access,
			Format,
			Channel
		>::type
		target_type;

	return 
		static_cast<target_type>
		(
			static_cast<Float>
			(
				color::channel_min
				<
					target_type
				>()
			)
			+
			f *
			(
				static_cast<Float>
				(
					color::channel_max
					<
						target_type
					>()
				)
				-
				static_cast<Float>
				(
					color::channel_min
					<
						target_type
					>()
				)
			)
		);
}

}
}

#endif
