//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_COMPARE_HPP_INCLUDED
#define MIZUIRO_COLOR_COMPARE_HPP_INCLUDED

#include <mizuiro/color/formats_are_compatible.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/detail/compare.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <mizuiro/detail/external_end.hpp>


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
		mizuiro::color::formats_are_compatible<
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

	typedef
	typename
	Color1::format::layout::order
	channels;

	// TODO: Make a fold operation for this?
	return
		mizuiro::color::detail::compare<
			false
		>:: template execute<
			typename
			boost::mpl::begin<
				channels
			>::type,
			typename
			boost::mpl::end<
				channels
			>::type
		>(
			_color1,
			_color2,
			_compare
		);
}

}
}

#endif
