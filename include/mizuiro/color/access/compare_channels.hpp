//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_COMPARE_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_COMPARE_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/access/compare_channels_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Format,
	typename StaticChannel,
	typename OtherChannel
>
inline
bool
compare_channels(
	mizuiro::color::format::store<
		Format
	> const &_format,
	StaticChannel const &_channel1,
	OtherChannel const &_channel2
)
{
	return
		compare_channels_adl(
			mizuiro::color::access::compare_channels_ns::tag(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			_format,
			_channel1,
			_channel2
		);
}

}
}
}

#endif
