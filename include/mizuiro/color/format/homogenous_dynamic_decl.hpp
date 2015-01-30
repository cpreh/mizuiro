//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/color/detail/dynamic_channel_array.hpp>
#include <mizuiro/color/format/homogenous_dynamic_fwd.hpp>
#include <mizuiro/color/layout/all_possible_channels.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/mpl/size.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename ChannelType,
	typename Space,
	mizuiro::size_type ChannelCount
>
struct homogenous_dynamic
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		homogenous_dynamic
	);
public:
	typedef
	ChannelType
	channel_type;

	typedef
	Space
	space;

	typedef
	mizuiro::color::detail::dynamic_channel_array<
		ChannelCount
	>
	channel_array;

	typedef
	mizuiro::color::layout::all_possible_channels<
		typename
		Space::required_channels
	>
	all_possible_channels;

	typedef
	mizuiro::array<
		mizuiro::size_type,
		mizuiro::mpl::size<
			all_possible_channels
		>()
	>
	channel_index_array;

	template<
		typename UsedChannels
	>
	explicit
	homogenous_dynamic(
		UsedChannels const &
	);

	homogenous_dynamic(
		homogenous_dynamic const &
	) noexcept;

	static mizuiro::size_type const element_count =
		ChannelCount;

	channel_array const channels;

	channel_index_array const indices;
};

}
}
}

#endif
