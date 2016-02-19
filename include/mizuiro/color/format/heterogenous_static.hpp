//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/color/format/heterogenous_static_fwd.hpp>
#include <mizuiro/mpl/size.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename ChannelBits,
	typename Layout
>
struct heterogenous_static
{
	static_assert(
		mizuiro::mpl::size<
			ChannelBits
		>()
		==
		mizuiro::mpl::size<
			typename
			Layout::channels
		>(),
		"Number of channels doesn't match the layout"
	);

	typedef
	ChannelBits
	channel_bits;

	typedef
	Layout
	layout;

	typedef
	typename
	Layout::channels
	channels;
};

}
}
}

#endif
