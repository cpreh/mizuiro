//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DECAY_CHANNEL_PROXY_HPP_INCLUDED
#define MIZUIRO_COLOR_DECAY_CHANNEL_PROXY_HPP_INCLUDED

#include <mizuiro/color/channel_proxy_fwd.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Pointer,
	typename ValueType,
	typename ChannelAccess
>
inline
ValueType
decay_channel_proxy(
	mizuiro::color::channel_proxy<
		Pointer,
		ValueType,
		ChannelAccess
	> const _proxy
)
{
	return
		_proxy.get();
}

template<
	typename T
>
inline
T
decay_channel_proxy(
	T _value
)
{
	return
		_value;
}

}
}

#endif
