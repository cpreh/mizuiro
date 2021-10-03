//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_ACCESS_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/access/channels_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/tag_of_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::color::access
{

template<
	typename Format
>
decltype(
	channels_adl(
		std::declval<
			mizuiro::color::access::channels_ns::tag
		>(),
		std::declval<
			mizuiro::color::format::make_tag_of<
				Format
			>
		>(),
		std::declval<
			mizuiro::color::format::store<
				Format
			>
		>()
	)
)
channels(
	mizuiro::color::format::store<
		Format
	> const &_format
)
{
	return
		channels_adl(
			mizuiro::color::access::channels_ns::tag(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			_format
		);
}

}

#endif
