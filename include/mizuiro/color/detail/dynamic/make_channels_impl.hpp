//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_IMPL_HPP_INCLUDED

#include <fcppt/metal/index_of.hpp>
#include <fcppt/metal/set/to_list.hpp>
#include <mizuiro/color/detail/dynamic/channel_index.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
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
				fcppt::metal::index_of<
					fcppt::metal::set::to_list<
						PossibleChannels
					>,
					metal::at<
						Channels,
						metal::number<
							Index::value
						>
					>
				>::value
			};
	}
};

}
}
}
}

#endif
