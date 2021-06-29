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
#include <fcppt/array/object_impl.hpp>
#include <fcppt/mpl/set/size.hpp>


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
	using
	channel_type
	=
	ChannelType;

	using
	space
	=
	Space;

	using
	channel_array
	=
	mizuiro::color::detail::dynamic::channel_array<
		ChannelCount
	>;

	using
	all_possible_channels
	=
	mizuiro::color::layout::all_possible_channels<
		typename
		Space::required_channels
	>;

	using
	channel_index_array
	=
	fcppt::array::object<
		mizuiro::size_type,
		fcppt::mpl::set::size<
			all_possible_channels
		>::value
	>;

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
