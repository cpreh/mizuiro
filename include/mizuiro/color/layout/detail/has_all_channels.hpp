//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_ALL_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_DETAIL_HAS_ALL_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/layout/detail/has_channel.hpp>
#include <mizuiro/mpl/all_of.hpp>
#include <mizuiro/mpl/bool.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{
namespace detail
{

template<
	typename Order1,
	typename Order2
>
using has_all_channels
=
mizuiro::mpl::bool_<
	mizuiro::mpl::all_of<
		Order1,
		mizuiro::color::layout::detail::has_channel<
			Order2
		>
	>()
>;

}
}
}
}

#endif
