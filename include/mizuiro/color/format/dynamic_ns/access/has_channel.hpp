//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_ACCESS_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_ACCESS_HAS_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/channel_index.hpp>
#include <mizuiro/color/access/has_channel_ns/tag.hpp>
#include <mizuiro/color/detail/dynamic/invalid_index.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/dynamic_ns/tag.hpp>
#include <mizuiro/color/format/dynamic_ns/access/channel_index.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace has_channel_ns
{

template<
	typename Format,
	typename Channel
>
inline
bool
has_channel_adl(
	mizuiro::color::access::has_channel_ns::tag,
	mizuiro::color::format::dynamic_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &_format,
	Channel const &_channel
)
{
	return
		mizuiro::color::access::channel_index<
			Format
		>(
			_format,
			_channel
		)
		!=
		mizuiro::color::detail::dynamic::invalid_index()
		;
}

}
}
}
}

#endif
