//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_CHANNEL_INDEX_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_CHANNEL_INDEX_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/access/channel_index_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>


namespace mizuiro::color::access
{

// TODO(philipp): Move this somewhere else
template<
	typename Format,
	typename Channel
>
inline
mizuiro::size_type
channel_index(
	mizuiro::color::format::store<
		Format
	> const &_format,
	Channel const &_channel
)
{
	return
		channel_index_adl(
			mizuiro::color::access::channel_index_ns::tag(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			_format,
			_channel
		);
}

}

#endif
