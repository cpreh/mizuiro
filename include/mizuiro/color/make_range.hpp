//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_MAKE_RANGE_HPP_INCLUDED
#define MIZUIRO_COLOR_MAKE_RANGE_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/access/channels.hpp>
#include <mizuiro/color/types/layout.hpp>
#include <mizuiro/range/make.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Color
>
inline
decltype(
	mizuiro::range::make(
		std::declval<
			mizuiro::color::types::layout<
				typename
				Color::format
			>
		>()
	)
)
make_range(
	Color const &_color
)
{
	static_assert(
		mizuiro::color::is_color<
			Color
		>::value,
		"Color must be a color type"
	);

	return
		mizuiro::range::make(
			mizuiro::color::access::channels(
				_color.format_store()
			)
		);
}

}
}

#endif
