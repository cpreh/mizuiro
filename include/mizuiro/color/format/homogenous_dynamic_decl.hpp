//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_DECL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/detail/dynamic/channel_array.hpp>
#include <mizuiro/color/format/homogenous_dynamic_fwd.hpp>
#include <mizuiro/color/layout/all_possible_channels.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


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
public:
	typedef
	ChannelType
	channel_type;

	typedef
	Space
	space;

	typedef
	mizuiro::color::detail::dynamic::channel_array<
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
	std::array<
		mizuiro::size_type,
		metal::size<
			all_possible_channels
		>::value
	>
	channel_index_array;

	template<
		typename Layout
	>
	explicit
	homogenous_dynamic(
		Layout const &
	);

	static constexpr mizuiro::size_type const element_count =
		ChannelCount;

	channel_array channels;

	channel_index_array indices;
};

}
}
}

#endif
