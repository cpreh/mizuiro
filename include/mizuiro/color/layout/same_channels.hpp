//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_SAME_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_SAME_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/layout/detail/has_all_channels.hpp>
#include <mizuiro/mpl/bool.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

template<
	typename Layout1,
	typename Layout2
>
using same_channels
=
mizuiro::mpl::bool_<
	mizuiro::color::layout::detail::has_all_channels<
		typename
		Layout1::order,
		typename
		Layout2::order
	>::value
	&&
	mizuiro::color::layout::detail::has_all_channels<
		typename
		Layout2::order,
		typename
		Layout1::order
	>::value
>;

}
}
}

#endif
