//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/color/format/heterogenous_static_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/size.hpp>
#include <mizuiro/detail/external_end.hpp>


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
		boost::mpl::size<
			ChannelBits
		>::value
		==
		boost::mpl::size<
			typename Layout::order
		>::value,
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
	Layout::order
	order;
};

}
}
}

#endif
