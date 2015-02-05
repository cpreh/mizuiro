//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_IMPL_HPP_INCLUDED

#include <mizuiro/color/detail/dynamic/channel_index.hpp>
#include <mizuiro/mpl/at.hpp>
#include <mizuiro/mpl/index_of.hpp>
#include <mizuiro/mpl/size.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace dynamic
{

template<
	typename PossibleChannels,
	typename Channels
>
struct make_channels_impl
{
	template<
		typename Index
	>
	constexpr
	mizuiro::color::detail::dynamic::channel_index
	operator()(
		Index
	) const
	{
		return
			mizuiro::color::detail::dynamic::channel_index{
				mizuiro::mpl::index_of<
					PossibleChannels,
					mizuiro::mpl::at<
						Channels,
						Index::value
					>
				>()
			};
	}
};

}
}
}
}

#endif
