#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_COPY_AND_CONVERT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_COPY_AND_CONVERT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{
template
<
	class Channel,
	class Float,
	class Src,
	class Dest
>
void
copy_and_convert_channel
(
	Src const &src,
	Dest &dest
)
{
	dest.template set<Channel>
	(
		denormalize<Dest,Channel,Float>
		(
			normalize<Src,Channel,Float>
			(
				src.template get<Channel>()
			)
		)
	);
}
}
}
}

#endif
