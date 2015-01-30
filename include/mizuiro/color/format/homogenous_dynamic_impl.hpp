//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_IMPL_HPP_INCLUDED

#include <mizuiro/color/detail/dynamic/initialize_indices.hpp>
#include <mizuiro/color/detail/dynamic/make_channels.hpp>
#include <mizuiro/color/format/homogenous_dynamic_decl.hpp>


template<
	typename ChannelType,
	typename Channels,
	mizuiro::size_type ChannelCount
>
template<
	typename UsedChannels
>
mizuiro::color::format::homogenous_dynamic<
	ChannelType,
	Channels,
	ChannelCount
>::homogenous_dynamic(
	UsedChannels const &
)
:
	channels(
		mizuiro::color::detail::dynamic::make_channels<
			all_possible_channels,
			UsedChannels
		>()
	),
	indices(
		mizuiro::color::detail::dynamic::initialize_indices<
			channel_index_array
		>(
			channels
		)
	)
{
}

template<
	typename ChannelType,
	typename Channels,
	mizuiro::size_type ChannelCount
>
mizuiro::color::format::homogenous_dynamic<
	ChannelType,
	Channels,
	ChannelCount
>::homogenous_dynamic(
	homogenous_dynamic const &
) noexcept
= default;

#endif
