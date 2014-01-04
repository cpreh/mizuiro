//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_CHANNEL_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_CHANNEL_VALUE_HPP_INCLUDED

#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/channel_value_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace channel_value_ns
{

template<
	typename Format,
	typename Channel
>
typename
Format::channel_type
channel_value_adl(
	mizuiro::color::types::channel_value_ns::tag,
	mizuiro::color::format::homogenous_ns::tag<
		Format
	> const &,
	Channel const &
);

}
}
}
}

#endif
