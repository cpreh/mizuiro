//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED

#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/convert/detail/copy_and_convert_channel.hpp>
#include <mizuiro/color/convert/detail/channel_to_max.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

// source and destination have an alpha channel, so convert
template
<
	class Src,
	class Dest
>
void
copy_or_max_alpha(
	Src const &_src,
	Dest &_dest
)
{
	if(
		!color::access::has_channel<
			typename Dest::format,
			channel::alpha
		>::execute(
			_dest.format_store()
		)
	)
		return;
	
	if(
		color::access::has_channel<
			typename Src::format,
			channel::alpha
		>::execute(
			_src.format_store()
		)
	)
		color::detail::copy_and_convert_channel<
			float
		>
		(
			channel::alpha(),
			_src,
			_dest
		);
	else
		color::detail::channel_to_max
		(
			_dest,
			channel::alpha()
		);

}

}
}
}

#endif
