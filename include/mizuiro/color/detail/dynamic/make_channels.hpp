//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/detail/dynamic/channel_array.hpp>
#include <mizuiro/color/detail/dynamic/make_channels_impl.hpp>
#include <fcppt/container/array/init.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/size.hpp>
#include <fcppt/config/external_end.hpp>


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
	brigand::size<
		Channels
	>::value
>
make_channels()
{
	return
		fcppt::container::array::init<
			mizuiro::color::detail::dynamic::channel_array<
				brigand::size<
					Channels
				>::value
			>
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
