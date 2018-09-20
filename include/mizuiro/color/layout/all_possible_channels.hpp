//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_ALL_POSSIBLE_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_ALL_POSSIBLE_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/undefined.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/append.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


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
brigand::append<
	brigand::list<
		mizuiro::color::channel::alpha,
		mizuiro::color::channel::undefined
	>,
	Channels
>;

}
}
}

#endif
