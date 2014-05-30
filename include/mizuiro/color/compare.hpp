//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_COMPARE_HPP_INCLUDED
#define MIZUIRO_COLOR_COMPARE_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/detail/compare.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/end.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
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
typename
boost::enable_if<
	boost::mpl::and_<
		std::is_same<
			typename Color1::format,
			typename Color2::format
		>,
		mizuiro::color::is_color<
			Color1
		>,
		mizuiro::color::is_color<
			Color2
		>
	>,
	bool
>::type
compare(
	Color1 const &_color1,
	Color2 const &_color2,
	CompareChannel const &_compare
)
{
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
