//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_MAX_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_MAX_ALPHA_HPP_INCLUDED

#include <mizuiro/color/convert/detail/channel_to_max.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/has_channel.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template
<
	class Color
>
typename 
boost::enable_if
<
	color::has_channel
	<
		typename Color::format,
		channel::alpha
	>, 
	void
>::type 
max_alpha(
	Color &_color
)
{
	color::detail::channel_to_max
	(
		_color,
		channel::alpha()
	);
}

}
}
}

#endif
