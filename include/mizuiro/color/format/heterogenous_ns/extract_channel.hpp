//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_EXTRACT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_EXTRACT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/extract_channel_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>


namespace mizuiro
{
namespace color
{
namespace access
{
namespace extract_channel_ns
{

template<
	typename Access,
	typename Format,
	typename Channel,
	typename Constness
>
mizuiro::color::types::channel_reference<
	Access,
	Format,
	Channel,
	Constness
>
extract_channel_adl(
	mizuiro::color::access::extract_channel_ns::tag,
	Access,
	mizuiro::color::format::heterogenous_ns::tag<
		Format
	>,
	mizuiro::color::format::store<
		Format
	> const &,
	Channel const &,
	Constness const &,
	mizuiro::color::types::pointer<
		Access,
		Format,
		Constness
	> const _data
)
{
	return
		mizuiro::color::types::channel_reference<
			Access,
			Format,
			Channel,
			Constness
		>(
			_data
		);
}

}
}
}
}

#endif
