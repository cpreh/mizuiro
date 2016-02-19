//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_ACCESS_COMPARE_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_ACCESS_COMPARE_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/access/compare_channels_ns/tag.hpp>
#include <mizuiro/color/detail/dynamic/channel_index.hpp>
#include <mizuiro/color/detail/dynamic/static_to_dynamic_channel.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/dynamic_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace compare_channels_ns
{

template<
	typename Format,
	typename StaticChannel
>
bool
compare_channels_adl(
	mizuiro::color::access::compare_channels_ns::tag,
	mizuiro::color::format::dynamic_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &,
	StaticChannel const &_channel1,
	mizuiro::color::detail::dynamic::channel_index const &_channel2
)
{
	return
		_channel2
		==
		mizuiro::color::detail::dynamic::static_to_dynamic_channel<
			Format
		>(
			_channel1
		);
}

}
}
}
}

#endif
