//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_MAKE_DYNAMIC_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_MAKE_DYNAMIC_CHANNELS_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/color/detail/dynamic_channel_array.hpp>
#include <mizuiro/color/detail/make_dynamic_channels_impl.hpp>
#include <mizuiro/mpl/size.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename PossibleChannels,
	typename Channels
>
inline
mizuiro::color::detail::dynamic_channel_array<
	mizuiro::mpl::size<
		Channels
	>()
>
make_dynamic_channels()
{
	return
		mizuiro::color::detail::make_dynamic_channels_impl<
			PossibleChannels,
			Channels,
			0
		>();
}

}
}
}

#endif
