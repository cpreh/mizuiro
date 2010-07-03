//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/homogenous_fwd.hpp>

namespace mizuiro
{
namespace color
{
namespace types
{

template<
	typename ChannelType,
	typename Layout,
	typename Channel
>
struct channel_value<
	color::homogenous<
		ChannelType,
		Layout
	>,
	Channel
>
{
	typedef ChannelType type;
};

}
}
}

#endif
