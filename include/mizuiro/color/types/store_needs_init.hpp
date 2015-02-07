//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_STORE_NEEDS_INIT_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_STORE_NEEDS_INIT_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/types/store_needs_init_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{

template<
	typename Format
>
using
store_needs_init
=
decltype(
	store_needs_init_adl(
		mizuiro::color::types::store_needs_init_ns::tag(),
		mizuiro::color::format::make_tag_of<
			Format
		>()
	)
);

}
}
}

#endif