//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_HSV_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_HSV_HPP_INCLUDED

#include <mizuiro/color/has_channel.hpp>
#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template
<
	typename Format
>
struct is_hsv
:
boost::mpl::and_
<
	has_channel
	<
		Format,
		channel::hue
	>,
	has_channel
	<
		Format,
		channel::saturation
	>,
	has_channel
	<
		Format,
		channel::value
	>
>
{
};

}
}

#endif
