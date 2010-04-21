#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/access/channel_min.hpp>
#include <mizuiro/color/access/channel_max.hpp>

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
typename 
types::channel_value
<
	Access,
	Format,
	Channel
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
				color::access::channel_min
				<
					Access,
					Format,
					Channel
				>()
			)
			+
			f *
			(
				static_cast<Float>
				(
					color::access::channel_max
					<
						Access,
						Format,
						Channel
					>()
				)
				-
				static_cast<Float>
				(
					color::access::channel_min
					<
						Access,
						Format,
						Channel
					>()
				)
			)
		);
}
}
}

#endif
