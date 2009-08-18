#ifndef MIZUIRO_COLOR_CONVERT_RGB_TO_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_RGB_TO_ALPHA_HPP_INCLUDED

#include <mizuiro/color/convert/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/is_alpha.hpp>
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
typename boost::enable_if
<
	boost::mpl::and_
	<
		is_alpha
		<
			Dest
		>,
		is_rgb
		<
			typename Src::layout
		>
	>,
	object
	<
		Dest
	> const
>::type
convert
(
	Src const &s
)
{
	object<
		Dest
	> dest;

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
