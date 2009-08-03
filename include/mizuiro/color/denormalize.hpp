#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

namespace mizuiro
{
// foobar
namespace color
{
template
<
	class Layout,
	class Channel,
	class Float
>
typename 
Layout::template channel_value_type<Channel>::type
denormalize
(
	Float const f
)
{
	typedef 
		typename 
		Layout::template channel_value_type<Channel>::type
		target_type;

	return 
		static_cast<target_type>
		(
			static_cast<Float>
			(
				Layout::template channel_min
				<
					Channel
				>()
			)
			+
			f *
			(
				static_cast<Float>
				(
					Layout::template channel_max
					<
						Channel
					>()
				)
				-
				static_cast<Float>
				(
					Layout::template channel_min
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
