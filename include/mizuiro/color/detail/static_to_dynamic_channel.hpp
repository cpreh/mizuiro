//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_STATIC_TO_DYNAMIC_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_STATIC_TO_DYNAMIC_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/format/dynamic_ns/static_to_dynamic_channel_fwd.hpp>


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
Format::available_channels
static_to_dynamic_channel(
	StaticChannel const &_channel
)
{
	return
		mizuiro::color::format::dynamic_ns::static_to_dynamic_channel<
			typename
			Format::available_channels
		>::execute(
			_channel
		);
}

}
}
}

#endif
