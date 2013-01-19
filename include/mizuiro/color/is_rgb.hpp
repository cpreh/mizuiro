//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_RGB_HPP_INCLUDED

#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/types/has_channel_static.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/or.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template
<
	typename Format
>
struct is_rgb
:
boost::mpl::or_
<
	color::types::has_channel_static
	<
		Format,
		channel::red
	>,
	color::types::has_channel_static
	<
		Format,
		channel::green
	>,
	color::types::has_channel_static
	<
		Format,
		channel::blue
	>
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
