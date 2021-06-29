//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_MAKE_CHANNELS_IMPL_HPP_INCLUDED

#include <mizuiro/color/detail/dynamic/channel_index.hpp>
#include <fcppt/mpl/size_type.hpp>
#include <fcppt/mpl/list/at.hpp>
#include <fcppt/mpl/list/index_of.hpp>
#include <fcppt/mpl/set/to_list.hpp>


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
				fcppt::mpl::list::index_of<
					fcppt::mpl::set::to_list<
						PossibleChannels
					>,
					fcppt::mpl::list::at<
						Channels,
						fcppt::mpl::size_type<
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
