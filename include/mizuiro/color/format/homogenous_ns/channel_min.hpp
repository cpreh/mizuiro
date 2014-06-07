//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_CHANNEL_MIN_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_CHANNEL_MIN_HPP_INCLUDED

#include <mizuiro/color/access/channel_min_ns/tag.hpp>
#include <mizuiro/color/detail/full_channel_min.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/channel_value.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace channel_min_ns
{

template<
	typename Format,
	typename Channel
>
mizuiro::color::types::channel_value<
	Format,
	Channel
>
channel_min_adl(
	mizuiro::color::access::channel_min_ns::tag,
	mizuiro::color::format::homogenous_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &,
	Channel const &
)
{
	return
		mizuiro::color::detail::full_channel_min<
			typename
			Format::channel_type
		>();
}

}
}
}
}

#endif
