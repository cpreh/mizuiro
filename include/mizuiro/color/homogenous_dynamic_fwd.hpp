//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_FWD_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_FWD_HPP_INCLUDED

#include <mizuiro/size_type.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename AvailableChannels,
	AvailableChannels AllChannels,
	mizuiro::size_type Size
>
struct homogenous_dynamic;

}
}

#endif
