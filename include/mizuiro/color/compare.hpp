//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_COMPARE_HPP_INCLUDED
#define MIZUIRO_COLOR_COMPARE_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/access/layout.hpp>
#include <mizuiro/color/detail/compare.hpp>
#include <mizuiro/color/format/compatible.hpp>
#include <mizuiro/range/all_of.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Color1,
	typename Color2,
	typename CompareChannel
>
bool
compare(
	Color1 const &_color1,
	Color2 const &_color2,
	CompareChannel const &_compare
)
{
	static_assert(
		mizuiro::color::format::compatible<
			typename Color1::format,
			typename Color2::format
		>::value,
		"Color formats must be compatible to be comparable"
	);

	static_assert(
		mizuiro::color::is_color<
			Color1
		>::value,
		"Color1 must be a color type"
	);

	static_assert(
		mizuiro::color::is_color<
			Color2
		>::value,
		"Color2 must be a color type"
	);

	return
		mizuiro::range::all_of(
			mizuiro::color::access::layout(
				_color1.format_store()
			),
			mizuiro::color::detail::compare<
				Color1,
				Color2,
				CompareChannel
			>(
				_color1,
				_color2,
				_compare
			)
		);
}

}
}

#endif
