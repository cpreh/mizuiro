//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_CHANNEL_INDEX_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_DYNAMIC_NS_CHANNEL_INDEX_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/access/channel_index_ns/tag.hpp>
#include <mizuiro/color/detail/dynamic/channel_to_pos.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/color/format/dynamic_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace channel_index_ns
{

template<
	typename Format,
	typename Channel
>
inline
mizuiro::size_type
channel_index_adl(
	mizuiro::color::access::channel_index_ns::tag,
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
		_format.get()->indices[
			mizuiro::color::detail::dynamic::channel_to_pos<
				Format
			>(
				_channel
			)
		];
}

}
}
}
}

#endif
