//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED

#include <mizuiro/color/homogenous_dynamic_fwd.hpp>
#include <mizuiro/access/homogenous_dynamic.hpp>
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
	typedef mizuiro::array<
		AvailableChannels,
		Size
	> channel_array;

	typedef mizuiro::array<
		size_type,
		AllChannels
	> channel_index_array;

	explicit
	homogenous_dynamic(
		channel_array const &
	);

	typedef ChannelType channel_type;

	static size_type const element_count = Size;

	channel_array const layout;

	channel_index_array const indices;
};

}
}

#endif
