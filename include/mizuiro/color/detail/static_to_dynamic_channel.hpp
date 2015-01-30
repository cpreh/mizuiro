//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_STATIC_TO_DYNAMIC_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_STATIC_TO_DYNAMIC_CHANNEL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/channel/tag.hpp>
#include <mizuiro/color/detail/channel_index.hpp>
#include <mizuiro/mpl/index_of.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Format,
	typename StaticChannel
>
inline
typename
mizuiro::color::detail::channel_index const
static_to_dynamic_channel(
	mizuiro::color::channel::tag<
		StaticChannel
	> const &
)
{
	return
		mizuiro::color::detail::channel_index{
			mizuiro::mpl::index_of<
				typename
				Format::all_possible_channels,
				StaticChannel
			>()
		};
}

}
}
}

#endif
