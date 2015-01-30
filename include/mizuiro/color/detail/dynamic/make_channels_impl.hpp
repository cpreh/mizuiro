//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_IMPL_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/color/detail/dynamic/channel_array.hpp>
#include <mizuiro/color/detail/dynamic/channel_index.hpp>
#include <mizuiro/mpl/at.hpp>
#include <mizuiro/mpl/index_of.hpp>
#include <mizuiro/mpl/size.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


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
	typename Channels,
	mizuiro::size_type Index,
	typename... Args
>
inline
typename
std::enable_if<
	Index
	==
	mizuiro::mpl::size<
		Channels
	>(),
	mizuiro::color::detail::dynamic::channel_array<
		mizuiro::mpl::size<
			Channels
		>()
	>
>::type
make_channels_impl(
	Args const & ..._args
)
{
	return
		mizuiro::color::detail::dynamic::channel_array<
			mizuiro::mpl::size<
				Channels
			>()
		>{{
			_args...
		}};
}

template<
	typename PossibleChannels,
	typename Channels,
	mizuiro::size_type Index,
	typename... Args
>
inline
typename
std::enable_if<
	Index
	<
	mizuiro::mpl::size<
		Channels
	>(),
	mizuiro::color::detail::dynamic::channel_array<
		mizuiro::mpl::size<
			Channels
		>()
	>
>::type
make_channels_impl(
	Args const & ..._args
)
{
	return
		mizuiro::color::detail::dynamic::make_channels_impl<
			PossibleChannels,
			Channels,
			Index + 1u
		>(
			_args...,
			mizuiro::color::detail::dynamic::channel_index{
				mizuiro::mpl::index_of<
					PossibleChannels,
					mizuiro::mpl::at<
						Channels,
						Index
					>
				>()
			}
		);
}

}
}
}
}

#endif
