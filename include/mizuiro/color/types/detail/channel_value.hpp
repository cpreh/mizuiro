//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_DETAIL_CHANNEL_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_DETAIL_CHANNEL_VALUE_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/detail/assert_channel.hpp>
#include <mizuiro/color/types/channel_value_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace detail
{

template<
	typename Format,
	typename Channel
>
struct channel_value
{
	MIZUIRO_COLOR_FORMAT_DETAIL_ASSERT_CHANNEL(
		Format,
		Channel
	);

	typedef
	decltype(
		channel_value_adl(
			std::declval<
				mizuiro::color::types::channel_value_ns::tag
			>(),
			mizuiro::color::format::make_tag_of<
				Format
			>(),
			std::declval<
				Channel
			>()
		)
	)
	type;
};

}
}
}
}

#endif
