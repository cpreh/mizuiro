//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_TYPES_SPACE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_TYPES_SPACE_HPP_INCLUDED

#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/color/types/space_ns/tag.hpp>


namespace mizuiro::color::types::space_ns
{
template<
	typename Format
>
typename
Format::layout::space
space_adl(
	mizuiro::color::types::space_ns::tag,
	mizuiro::color::format::static_ns::tag<
		Format
	>
);

}

#endif
