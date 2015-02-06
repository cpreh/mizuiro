//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_ACCESS_CHANNEL_INDEX_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_ACCESS_CHANNEL_INDEX_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/access/channel_index_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/color/format/static_ns/types/static_channels.hpp>
#include <mizuiro/color/types/static_channels.hpp>
#include <mizuiro/mpl/index_of.hpp>


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
mizuiro::size_type
channel_index_adl(
	mizuiro::color::access::channel_index_ns::tag,
	mizuiro::color::format::static_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &,
	Channel const &
)
{
	return
		mizuiro::mpl::index_of<
			mizuiro::color::types::static_channels<
				Format
			>,
			Channel
		>();
}

}
}
}
}

#endif
