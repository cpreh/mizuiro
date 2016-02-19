//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/detail/dynamic/channel_array.hpp>
#include <mizuiro/color/detail/dynamic/make_channels_impl.hpp>
#include <mizuiro/detail/array_init_each.hpp>
#include <mizuiro/mpl/size.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace dynamic
{

template<
	typename PossibleChannels,
	typename Channels
>
inline
mizuiro::color::detail::dynamic::channel_array<
	mizuiro::mpl::size<
		Channels
	>()
>
make_channels()
{
	return
		mizuiro::detail::array_init_each<
			mizuiro::mpl::size<
				Channels
			>()
		>(
			mizuiro::color::detail::dynamic::make_channels_impl<
				PossibleChannels,
				Channels
			>{}
		);
}

}
}
}
}

#endif
