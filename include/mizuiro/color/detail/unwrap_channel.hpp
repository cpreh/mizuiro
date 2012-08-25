//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_UNWRAP_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_UNWRAP_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/channel_proxy_fwd.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename T
>
T
unwrap_channel(
	T const &_value
)
{
	return _value;
}

template<
	typename Pointer,
	typename ValueType,
	typename ChannelAccess
>
ValueType
unwrap_channel(
	mizuiro::color::channel_proxy<
		Pointer,
		ValueType,
		ChannelAccess
	> const &_proxy
)
{
	return
		_proxy.get();
}

}
}
}

#endif
