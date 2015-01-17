//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_CHANNEL_REFERENCE_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_CHANNEL_REFERENCE_NORMAL_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/channel_proxy_impl.hpp>
#include <mizuiro/color/detail/bit_channel_access_normal.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/channel_reference_ns/tag.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{
namespace channel_reference_ns
{

template<
	typename Format,
	typename Channel,
	typename Constness
>
mizuiro::color::channel_proxy<
	mizuiro::color::types::pointer<
		mizuiro::access::normal,
		Format,
		Constness
	>,
	mizuiro::color::types::channel_value<
		Format,
		Channel
	>,
	mizuiro::color::detail::bit_channel_access_normal<
		Format,
		Channel
	>
>
channel_reference_adl(
	mizuiro::color::types::channel_reference_ns::tag,
	mizuiro::access::normal,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>,
	Channel,
	Constness
);

}
}
}
}

#endif
