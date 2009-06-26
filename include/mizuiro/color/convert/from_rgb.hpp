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
/*
template
<
	template<class>
	class Gray,
	class Color
>
*/


template
<
	typename Dest,
	typename Src
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
		s,
		dest
	);

	detail::copy_and_convert_channel
	<
		channel::green,
		float
	>
	(
		s,
		dest
	);

	detail::copy_and_convert_channel
	<
		channel::blue,
		float
	>
	(
		s,
		dest
	);

	detail::copy_or_max_alpha
	(
		s,
		dest
	);
	
	return dest;
}
}
}

#endif
