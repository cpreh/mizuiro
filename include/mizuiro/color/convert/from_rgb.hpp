#ifndef MIZUIRO_COLOR_CONVERT_FROM_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_FROM_RGB_HPP_INCLUDED

#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/color/convert/detail/copy_and_convert_channel.hpp>
#include <mizuiro/color/convert/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/is_rgb.hpp>

namespace mizuiro
{
namespace color
{
template
<
	typename Src,
	typename Dest
>
typename
boost::enable_if
<
	boost::mpl::and_
	<
		is_rgb<Src>,
		is_rgb<Dest>
	>,
	Dest const
>::type
convert
(
	Src const &s
)
{
	Dest dest;

	detail::copy_and_convert_channel
	<
		channel::red,
		float
	>
	(
		src,
		dest
	);

	detail::copy_and_convert_channel
	<
		channel::green,
		float
	>
	(
		src,
		dest
	);

	detail::copy_and_convert_channel
	<
		channel::blue,
		float
	>
	(
		src,
		dest
	);

	detail::copy_or_max_alpha
	(
		src,
		dest
	);
	
	return dest;
}
}
}

#endif
