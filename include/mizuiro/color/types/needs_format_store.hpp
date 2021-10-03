//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_NEEDS_FORMAT_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_NEEDS_FORMAT_STORE_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/types/needs_format_store_ns/tag.hpp>


namespace mizuiro::color::types
{

template<
	typename Format
>
using
needs_format_store
=
decltype(
	needs_format_store_adl(
		mizuiro::color::types::needs_format_store_ns::tag(),
		mizuiro::color::format::make_tag_of<
			Format
		>()
	)
);

}

#endif
