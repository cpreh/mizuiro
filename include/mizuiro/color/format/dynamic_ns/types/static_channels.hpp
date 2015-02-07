//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_TYPES_STATIC_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_TYPES_STATIC_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/format/dynamic_ns/tag.hpp>
#include <mizuiro/color/types/static_channels_ns/tag.hpp>
#include <mizuiro/mpl/list.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace static_channels_ns
{

template<
	typename Format
>
mizuiro::mpl::list<>
static_channels_adl(
	mizuiro::color::types::static_channels_ns::tag,
	mizuiro::color::format::dynamic_ns::tag<
		Format
	>
);

}
}
}
}

#endif