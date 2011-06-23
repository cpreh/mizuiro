//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_HPP_INCLUDED

#include <mizuiro/color/homogenous_dynamic_fwd.hpp>
#include <mizuiro/size_type.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	mizuiro::size_type Size
>
struct homogenous_dynamic
{
	typedef ChannelType channel_type;

	static size_type const element_count = Size;
};

}
}

#endif
