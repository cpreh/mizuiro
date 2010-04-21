#ifndef MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED

#if 0
#include <mizuiro/color/homogenous_fwd.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/detail/channel_min.hpp>
#include <mizuiro/color/detail/channel_max.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/mpl/size.hpp>
#endif

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout
>
struct homogenous
{
	typedef ChannelType channel_type;

	typedef Layout layout;

#if 0
	template<
		typename Constness
	>
	struct reference {
		typedef proxy<
			homogenous<
				channel_type,
				layout,
				AccessTypes
			>,
			Constness
		> type;
	};

	static size_type const element_count
		= boost::mpl::size<
			typename layout::order
		>::value;
	
	template<
		typename Channel,
		typename Constness
	>
	struct extract_channel
	:
	access_types:: template extract_channel<
		Channel,
		Constness
	>
	{};

	template<
		typename Channel
	>
	static typename channel_value_type<Channel>::type
	channel_max()
	{
		return detail::channel_max<
			typename channel_value_type<
				Channel
			>::type
		>::get();
	}
#endif
};

}
}

#endif
