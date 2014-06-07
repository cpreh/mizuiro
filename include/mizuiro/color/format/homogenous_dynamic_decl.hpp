//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/color/format/homogenous_dynamic_fwd.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstddef>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename ChannelType,
	typename AvailableChannels,
	mizuiro::size_type ChannelCount,
	mizuiro::size_type NumAvailableChannels
>
struct homogenous_dynamic
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		homogenous_dynamic
	);
public:
	typedef
	AvailableChannels
	available_channels;

	typedef
	mizuiro::array<
		AvailableChannels,
		ChannelCount
	>
	channel_array;

	typedef
	mizuiro::array<
		mizuiro::size_type,
		NumAvailableChannels
	>
	channel_index_array;

	explicit
	homogenous_dynamic(
		channel_array const &
	);

	typedef
	ChannelType
	channel_type;

	static
	mizuiro::size_type const element_count
		= ChannelCount;

	typedef
	channel_array
	layout;

	channel_array const order;

	channel_index_array const indices;
};

}
}
}

#endif
