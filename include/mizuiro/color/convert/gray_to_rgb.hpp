#ifndef MIZUIRO_COLOR_CONVERT_GRAY_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_GRAY_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/convert/detail/max_alpha.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>
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
	class Dest,
	class Src
>
typename
boost::enable_if
<
	boost::mpl::and_
	<
		is_rgb
		<
			Dest
		>,
		is_gray
		<
			typename Src::format
		>
	>,
	object<
		Dest
	> const
>::type
convert(
	Src const &src
)
{
	typedef object<
		Dest
	> dest_object;

	dest_object dest;

	detail::max_alpha
	(
		dest
	);
	
	float const src_normalized = 
		normalize
		<
			channel::gray,
			float
		>
		(
			src
		);

	dest.template set<channel::red>
	(
		denormalize<
			typename dest_object::access,
			typename dest_object::format,
			channel::red
		>
		(
			0.3f * src_normalized
		)
	);

	dest.template set<channel::green>
	(
		denormalize<
			typename dest_object::access,
			typename dest_object::format,
			channel::green
		>
		(
			0.59f * src_normalized
		)
	);

	dest.template set<channel::blue>
	(
		denormalize<
			typename dest_object::access,
			typename dest_object::format,
			channel::blue
		>
		(
			0.11f * src_normalized
		)
	);

	return dest;
}

}
}

#endif
