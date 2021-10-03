//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_TYPES_CHANNEL_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_TYPES_CHANNEL_VALUE_HPP_INCLUDED

#include <mizuiro/color/detail/heterogenous/channel_bits.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/types/channel_value_ns/tag.hpp>
#include <mizuiro/detail/uint_least.hpp>


namespace mizuiro::color::types::channel_value_ns
{

template<
	typename Format,
	typename Channel
>
mizuiro::detail::uint_least<
	mizuiro::color::detail::heterogenous::channel_bits<
		Format,
		Channel
	>
>
channel_value_adl(
	mizuiro::color::types::channel_value_ns::tag,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>,
	Channel const &
);

}

#endif
