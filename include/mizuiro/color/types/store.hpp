//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_STORE_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/types/store_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{

template<
	typename Format
>
using store
=
decltype(
	store_adl(
		std::declval<
			mizuiro::color::types::store_ns::tag
		>(),
		mizuiro::color::format::make_tag_of<
			Format
		>()
	)
);

}
}
}

#endif
