#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

#include <mizuiro/color/detail/channel_ref.hpp>
#include <mizuiro/detail/const_tag.hpp>

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
typename detail::channel_ref
<
	typename Color::proxy::layout,
	Channel,
	mizuiro::detail::const_tag
>::type
denormalize
(
	Float const f
)
{
	typedef 
		typename detail::channel_ref
		<
			typename Color::proxy::layout,
			Channel,
			mizuiro::detail::const_tag
		>::type target_type;

	return 
		static_cast<target_type>
		(
			Color::layout::template channel_min
			<
				Channel
			>()
			+
			f*
			(
				Color::layout::template channel_max
				<
					Channel
				>()
				-
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
