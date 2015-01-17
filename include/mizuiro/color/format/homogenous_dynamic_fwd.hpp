//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_FWD_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_FWD_HPP_INCLUDED

#include <mizuiro/enum_size.hpp>
#include <mizuiro/size_type.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename ChannelType,
	typename AvailableChannels,
	mizuiro::size_type ChannelCount,
	mizuiro::size_type NumAvailableChannels =
		mizuiro::enum_size<
			AvailableChannels
		>::value
>
struct homogenous_dynamic;

}
}
}

#endif
