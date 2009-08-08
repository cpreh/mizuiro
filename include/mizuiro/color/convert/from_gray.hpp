#ifndef MIZUIRO_COLOR_CONVERT_FROM_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_FROM_GRAY_HPP_INCLUDED

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
typename boost::enable_if
<
	boost::mpl::and_
	<
		is_gray
		<
			Dest
		>,
		is_gray
		<
			typename Src::layout
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
			normalize
			<
				channel::gray,
				float
			>
			(
				src
			)
		)
	);

	return dest;
}

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
			typename Src::layout
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
	object<
		Dest
	> dest;

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
			0.11f * src_normalized
		)
	);

	return dest;
}

}
}

#endif
