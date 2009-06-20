#ifndef MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/detail/homogenous_layout.hpp>
#include <mizuiro/color/detail/channel_min.hpp>
#include <mizuiro/color/detail/channel_max.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/mpl/size.hpp>
#include <boost/tr1/array.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout
>
struct homogenous {
	typedef ChannelType channel_type;
	typedef channel_type value_type;
	typedef value_type *pointer;
	typedef value_type const *const_pointer;
	typedef Layout layout;

	typedef proxy<
		detail::homogenous_layout<
			channel_type &,
			pointer,
			layout
		>
	> reference;

	typedef proxy<
		detail::homogenous_layout<
			channel_type const &,
			const_pointer,
			layout
		>
	> const_reference;

	static size_type const element_count
		= boost::mpl::size<
			typename layout::order
		>::value;
	
	typedef std::tr1::array<
		ChannelType,
		element_count
	> store;

	static value_type
	channel_min()
	{
		return detail::channel_min<
			value_type
		>::get();
	}

	static value_type
	channel_max()
	{
		return detail::channel_max<
			value_type
		>::get();
	}
};

}
}

#endif
