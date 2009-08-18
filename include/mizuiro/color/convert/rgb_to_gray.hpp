#ifndef MIZUIRO_COLOR_CONVERT_RGB_TO_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_RGB_TO_GRAY_HPP_INCLUDED

#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/gray.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/is_gray.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{
template
<
	typename Dest,
	typename Src
>
typename
boost::enable_if
<
	boost::mpl::and_<
		is_gray
		<
			Dest
		>,
		is_rgb
		<
			typename Src::format
		>
	>,
	object<
		Dest
	> const
>::type
convert
(
	Src const &src
)
{
	object<
		Dest
	> dest;

	float const sum = 
		normalize
		<
			channel::red,
			float
		>(src)
		+
		normalize
		<
			channel::green,
			float
		>(src)
		+
		normalize
		<
			channel::blue,
			float
		>(src);
	
	dest.template set
	<
		channel::gray
	>
	(
		denormalize
		<
			Dest,
			channel::gray,
			float
		>
		(
			sum / 3.0f
		)
	);

	return dest;
}

}
}

#endif
