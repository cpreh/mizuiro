//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_CHANNEL_MAX_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_CHANNEL_MAX_HPP_INCLUDED

#include <mizuiro/color/access/channel_max_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/detail/assert_channel.hpp>
#include <mizuiro/color/types/channel_value.hpp>


namespace mizuiro::color::access
{

template<
	typename Format,
	typename Channel
>
mizuiro::color::types::channel_value<
	Format,
	Channel
>
channel_max(
	mizuiro::color::format::store<
		Format
	> const &_format,
	Channel const &_channel
)
{
	MIZUIRO_COLOR_FORMAT_DETAIL_ASSERT_CHANNEL(
		Format,
		Channel
	);

	return
		channel_max_adl(
			mizuiro::color::access::channel_max_ns::tag(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			_format,
			_channel
		);
}

}

#endif
