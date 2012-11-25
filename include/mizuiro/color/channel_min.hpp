//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CHANNEL_MIN_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_MIN_HPP_INCLUDED

#include <mizuiro/color/format_store_fwd.hpp>
#include <mizuiro/color/access/channel_min.hpp>
#include <mizuiro/color/types/channel_value.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Format,
	typename Channel
>
typename mizuiro::color::types::channel_value<
	Format,
	Channel
>::type
channel_min(
	mizuiro::color::format_store<
		Format
	> const &_format,
	Channel const &_channel
)
{
	return
		mizuiro::color::access::channel_min<
			Format,
			Channel
		>::execute(
			_format,
			_channel
		);
}

}
}

#endif
