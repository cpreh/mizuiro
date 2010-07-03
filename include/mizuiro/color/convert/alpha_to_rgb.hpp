//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_ALPHA_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_ALPHA_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/convert/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/is_alpha.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
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
		is_rgb
		<
			Dest
		>,
		is_alpha
		<
			typename Src::format
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
	> dest(
		init::red %= 1.0,
		init::blue %= 1.0,
		init::green %= 1.0
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
