#ifndef MIZUIRO_COLOR_CONVERT_SCALAR_TO_SCALAR_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_SCALAR_TO_SCALAR_HPP_INCLUDED

#include <mizuiro/color/is_scalar.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/front.hpp>
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
		is_scalar
		<
			Dest
		>,
		is_scalar
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

	typedef typename boost::mpl::front<
		typename Dest::layout::order
	>::type dest_channel;

	dest.template set
	<
		dest_channel
	>
	(
		denormalize
		<
			Dest,
			dest_channel,
			float
		>
		(
			normalize
			<
				typename boost::mpl::front<
					typename Src::layout::layout::order
				>::type,
				float
			>
			(
				src
			)
		)
	);

	return dest;
}

}
}

#endif
