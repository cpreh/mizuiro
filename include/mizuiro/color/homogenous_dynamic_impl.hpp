//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_IMPL_HPP_INCLUDED

#include <mizuiro/color/homogenous_dynamic_decl.hpp>
#include <mizuiro/color/detail/initialize_dynamic_indices.hpp>


template<
	typename ChannelType,
	typename AvailableChannels,
	AvailableChannels AllChannels,
	mizuiro::size_type Size
>
mizuiro::color::homogenous_dynamic<
	ChannelType,
	AvailableChannels,
	AllChannels,
	Size
>::homogenous_dynamic(
	channel_array const &_order
)
:
	order(
		_order
	),
	indices(
		color::detail::initialize_dynamic_indices<
			channel_index_array
		>(
			order
		)
	)
{
}

#endif
