#ifndef MIZUIRO_COLOR_CONVERT_FROM_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_FROM_GRAY_HPP_INCLUDED

#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/convert/detail/max_alpha.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>

namespace mizuiro
{
namespace color
{

template
<
	class Dest,
	class Base,
	template<class T>
	class Color
>
typename
boost::enable_if
<
	is_rgb<Dest>,
	Dest const
>::type
convert(
	Color
	<
		homogenous
		<
			Base,
			layout::gray
		>
	> const &src
)
{
	Dest dest;

	detail::max_alpha
	(
		dest
	);
	
	float const src_normalized = 
		normalize
		<
			Color
			<
				homogenous<Base,layout::gray>
			>,
			channel::gray,
			float
		>
		(
			src
		);

	dest.template set<channel::red>
	(
		denormalize<Dest,channel::red,float>
		(
			0.3f * src_normalized
		)
	);

	dest.template set<channel::green>
	(
		denormalize<Dest,channel::green,float>
		(
			0.59f * src_normalized
		)
	);

	dest.template set<channel::blue>
	(
		denormalize<Dest,channel::blue,float>
		(
			0.11 * src_normalized
		)
	);

	return dest;
}

}
}

#endif
