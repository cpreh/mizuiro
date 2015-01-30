//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_CHANNEL_TO_POS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_CHANNEL_TO_POS_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/channel/tag.hpp>
#include <mizuiro/color/detail/dynamic/channel_index.hpp>
#include <mizuiro/color/detail/dynamic/static_to_dynamic_channel.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace dynamic
{

template<
	typename Format
>
inline
mizuiro::size_type
channel_to_pos(
	mizuiro::color::detail::dynamic::channel_index const _channel
)
{
	return
		_channel.get();
}

template<
	typename Format,
	typename Channel
>
inline
mizuiro::size_type
channel_to_pos(
	mizuiro::color::channel::tag<
		Channel
	> const &
)
{
	return
		mizuiro::color::detail::dynamic::channel_to_pos<
			Format
		>(
			mizuiro::color::detail::dynamic::static_to_dynamic_channel<
				Format
			>(
				Channel()
			)
		);
}

}
}
}
}

#endif
