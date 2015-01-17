//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_IMPL_HPP_INCLUDED

#include <mizuiro/color/detail/initialize_dynamic_indices.hpp>
#include <mizuiro/color/format/homogenous_dynamic_decl.hpp>


template<
	typename ChannelType,
	typename AvailableChannels,
	mizuiro::size_type ChannelCount,
	mizuiro::size_type NumAvailableChannels
>
mizuiro::color::format::homogenous_dynamic<
	ChannelType,
	AvailableChannels,
	ChannelCount,
	NumAvailableChannels
>::homogenous_dynamic(
	channel_array const &_order
)
:
	order(
		_order
	),
	indices(
		mizuiro::color::detail::initialize_dynamic_indices<
			channel_index_array
		>(
			order
		)
	)
{
}

template<
	typename ChannelType,
	typename AvailableChannels,
	mizuiro::size_type ChannelCount,
	mizuiro::size_type NumAvailableChannels
>
mizuiro::color::format::homogenous_dynamic<
	ChannelType,
	AvailableChannels,
	ChannelCount,
	NumAvailableChannels
>::homogenous_dynamic(
	homogenous_dynamic const &
) noexcept
= default;

#endif
