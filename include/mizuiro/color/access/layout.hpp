//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_LAYOUT_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_LAYOUT_HPP_INCLUDED

#include <mizuiro/color/access/layout_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/tag_of_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Format
>
// TODO: Make a typedef for this?
decltype(
	layout_adl(
		std::declval<
			mizuiro::color::access::layout_ns::tag
		>(),
		std::declval<
			typename
			mizuiro::color::format::tag_of<
				Format
			>::type
		>(),
		std::declval<
			mizuiro::color::format::store<
				Format
			>
		>()
	)
)
layout(
	mizuiro::color::format::store<
		Format
	> const &_format
)
{
	return
		layout_adl(
			mizuiro::color::access::layout_ns::tag(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			_format
		);
}

}
}
}

#endif
