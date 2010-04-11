#ifndef MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/homogenous_fwd.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/detail/channel_min.hpp>
#include <mizuiro/color/detail/channel_max.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/mpl/size.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout,
	typename AccessTypes
>
struct homogenous
{
	typedef AccessTypes access_types;
	typedef typename access_types::channel_type channel_type;
	typedef Layout layout;

	typedef homogenous<
		ChannelType,
		Layout
	> normal;

	template<
		typename Access
	>
	struct replace_access {
		typedef homogenous<
			ChannelType,
			Layout,
			Access
		> type;
	};

	template<
		typename Channel,
		typename Constness
	>
	struct channel_reference
	:
	AccessTypes:: template channel_reference<
		Channel,
		Constness
	>
	{};

	template<
		typename Channel
	>
	struct channel_value_type
	:
	AccessTypes:: template channel_value_type<
		Channel
	>
	{};

	template<
		typename Constness
	>
	struct pointer
	:
	AccessTypes:: template pointer<
		Constness
	>
	{};

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
	
	typedef typename AccessTypes::store store;

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
	channel_min()
	{
		return detail::channel_min<
			typename channel_value_type<
				Channel
			>::type
		>::get();
	}

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
};

}
}

#endif
