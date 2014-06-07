//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_CHANNEL_REFERENCE_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_CHANNEL_REFERENCE_RAW_HPP_INCLUDED

#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/channel_proxy_impl.hpp>
#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/detail/raw_channel_access.hpp>
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
		::mizuiro::access::raw,
		Format,
		Constness
	>,
	mizuiro::color::types::channel_value<
		Format,
		Channel
	>,
	mizuiro::color::detail::raw_channel_access<
		mizuiro::color::types::channel_value<
			Format,
			Channel
		>
	>
>
channel_reference_adl(
	mizuiro::color::types::channel_reference_ns::tag,
	mizuiro::access::raw,
	mizuiro::color::format::homogenous_ns::tag<
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
