//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_BASE_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_BASE_HPP_INCLUDED

#include <mizuiro/color/channel/alpha_fwd.hpp>
#include <mizuiro/color/channel/undefined_fwd.hpp>
#include <mizuiro/color/layout/detail/has_all_channels.hpp>
#include <mizuiro/mpl/list.hpp>
#include <mizuiro/mpl/include/list.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

/**
\brief A typedef helper class used to define color spaces

TODO: Use better notation here
PossibleChannels specifies the list of channels that are possible for this
color space. Every element of Order must either be
mizuiro::color::channel::alpha, mizuiro::color::channel::undefined or it must
be an element of PossibleChannels.

<code>typedef Order order</code>

A color space consists of possible channels (e.g. red, green, blue), possibly
including alpha channels (to include transparency which is not part of the
traditional color space definition) or undefined channels (which are purely
used as an efficient data representation mechanism). Alpha channels will never
contribute 'color' while undefined channels will be ignored.

TODO: Should a color space impose limits on the number of possible channels?

\tparam Order A mizuiro::mpl::list consisting of \link color_channel Color
Channels\endlink

\tparam PossibleChannels A variadic template list consisting of \link
color_channel Color Channels\endlink
*/
template<
	typename Order,
	typename... PossibleChannels
>
struct base
{
	typedef
	Order
	order;

	static_assert(
		mizuiro::color::layout::detail::has_all_channels<
			order,
			mizuiro::mpl::list<
				mizuiro::color::channel::alpha,
				mizuiro::color::channel::undefined,
				PossibleChannels...
			>
		>::value,
		"Invalid channel in color space"
	);

	// TODO: Is it ok when channel are missing (e.g. there is only a red channel in rgb)?

	// TODO: Check for duplicates
};

}
}
}

#endif
