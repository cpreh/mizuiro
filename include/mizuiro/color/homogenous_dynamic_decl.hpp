//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED

#include <mizuiro/color/homogenous_dynamic_fwd.hpp>
#include <mizuiro/color/access/homogenous_dynamic.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename AvailableChannels,
	AvailableChannels AllChannels,
	mizuiro::size_type Size
>
struct homogenous_dynamic
{
	typedef AvailableChannels available_channels;

	typedef typename mizuiro::array<
		AvailableChannels,
		Size
	>::type channel_array;

	typedef typename mizuiro::array<
		size_type,
		AllChannels
	>::type channel_index_array;

	explicit
	homogenous_dynamic(
		channel_array const &
	);

	typedef ChannelType channel_type;

	static size_type const element_count = Size;

	typedef channel_array layout;

	channel_array const order;

	channel_index_array const indices;
};

}
}

#endif
