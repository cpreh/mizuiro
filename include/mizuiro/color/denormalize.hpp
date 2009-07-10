#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

namespace mizuiro
{
namespace color
{
template
<
	class Color,
	class Channel,
	class Float
>
typename 
Color::layout::template channel_value_type<Channel>::type
denormalize
(
	Float const f
)
{
	typedef 
		typename 
		Color::layout::template channel_value_type<Channel>::type
		target_type;

	return 
		static_cast<target_type>
		(
			static_cast<Float>
			(
				Color::layout::template channel_min
				<
					Channel
				>()
			)
			+
			f*
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
			)
		);
}
}
}

#endif
