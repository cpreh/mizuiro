//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_STATIC_TO_DYNAMIC_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_STATIC_TO_DYNAMIC_CHANNEL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/channel/tag.hpp>
#include <mizuiro/color/detail/dynamic/channel_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/index_of.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace dynamic
{

template<
	typename Format,
	typename StaticChannel
>
inline
typename
mizuiro::color::detail::dynamic::channel_index
static_to_dynamic_channel(
	mizuiro::color::channel::tag<
		StaticChannel
	> const &
)
{
	return
		mizuiro::color::detail::dynamic::channel_index{
			brigand::index_of<
				typename
				Format::all_possible_channels,
				StaticChannel
			>::value
		};
}

}
}
}
}

#endif
