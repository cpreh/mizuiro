//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_ACCESS_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_ACCESS_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/access/channels_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/dynamic_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace channels_ns
{

template<
	typename Format
>
inline
typename
Format::channel_array const &
channels_adl(
	mizuiro::color::access::channels_ns::tag,
	mizuiro::color::format::dynamic_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &_format
)
{
	return
		_format.get()->channels;
}

}
}
}
}

#endif
