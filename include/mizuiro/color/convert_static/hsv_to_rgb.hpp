//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_HSV_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_HSV_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/is_hsv.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/hsv_to_rgb.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace convert_static
{

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
		color::is_rgb
		<
			Dest
		>,
		color::is_hsv
		<
			typename Src::format
		>
	>,
	color::object<
		Dest
	> const
>::type
convert(
	Src const &_source
)
{
	return
		conversion::hsv_to_rgb<
			Dest
		>(
			_source
		);
}

}
}
}

#endif
