//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_TYPES_LAYOUT_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_TYPES_LAYOUT_HPP_INCLUDED

#include <mizuiro/color/format/dynamic_ns/tag.hpp>
#include <mizuiro/color/types/layout_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace layout_ns
{

template<
	typename Format
>
typename
Format::channel_array
layout_adl(
	mizuiro::color::types::layout_ns::tag,
	mizuiro::color::format::dynamic_ns::tag<
		Format
	>
);

}
}
}
}

#endif
