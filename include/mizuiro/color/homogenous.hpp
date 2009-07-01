#ifndef MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/detail/channel_min.hpp>
#include <mizuiro/color/detail/channel_max.hpp>
#include <mizuiro/detail/const_tag.hpp>
#include <mizuiro/detail/nonconst_tag.hpp>
#include <mizuiro/detail/apply_const.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/mpl/size.hpp>
#include <boost/tr1/array.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout,
	typename Pointer = ChannelType *
>
struct homogenous {
	typedef ChannelType channel_type;
	typedef channel_type value_type;
	typedef Pointer pointer;
	typedef Pointer const const_pointer;
	typedef Layout layout;

	template<
		typename T
	>
	struct replace_pointer {
		typedef homogenous<
			ChannelType,
			Layout,
			T
		> type;
	};

	template<
		typename Channel,
		typename Constness
	>
	struct channel_reference {
		typedef typename mizuiro::detail::apply_const<
			channel_type &,
			Constness
		>::type type;
	};

	typedef proxy<
		homogenous<
			channel_type,
			layout,
			Pointer
		>,
		mizuiro::detail::nonconst_tag
	> reference;

	typedef proxy<
		homogenous<
			channel_type,
			layout,
			Pointer
		>,
		mizuiro::detail::const_tag
	> const_reference;

	static size_type const element_count
		= boost::mpl::size<
			typename layout::order
		>::value;
	
	typedef std::tr1::array<
		ChannelType,
		element_count
	> store;

	template<
		typename Channel
	>
	static value_type
	channel_min()
	{
		return detail::channel_min<
			value_type
		>::get();
	}

	template<
		typename Channel
	>
	static value_type
	channel_max()
	{
		return detail::channel_max<
			value_type
		>::get();
	}

	template<
		typename Channel
	>
	struct channel_value_type {
		typedef value_type type;
	};
};

}
}

#endif
