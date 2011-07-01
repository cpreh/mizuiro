//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_STATIC_LUMINANCE_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_STATIC_LUMINANCE_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/conversion/luminance_to_rgb.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/is_luminance.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{
namespace convert_static
{

template
<
	class Dest,
	class Src
>
typename
boost::enable_if<
	boost::mpl::and_<
		color::is_rgb<
			Dest
		>,
		color::is_luminance<
			typename Src::format
		>
	>,
	color::object<
		Dest
	> const
>::type
convert(
	Src const &_src
)
{
	return
		conversion::luminance_to_rgb<
			Dest
		>(
			_src
		);
}

}
}
}

#endif
