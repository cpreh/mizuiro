//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_ALL_POSSIBLE_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_ALL_POSSIBLE_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/undefined.hpp>
#include <mizuiro/mpl/cons.hpp>
#include <mizuiro/mpl/include/list.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

template<
	typename Channels
>
using
all_possible_channels
=
mizuiro::mpl::cons<
	mizuiro::color::channel::alpha,
	mizuiro::mpl::cons<
		mizuiro::color::channel::undefined,
		Channels
	>
>;

}
}
}

#endif
