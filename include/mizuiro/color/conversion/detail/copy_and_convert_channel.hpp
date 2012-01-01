//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_AND_CONVERT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_AND_CONVERT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/normalize.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template
<
	class Float,
	class Channel,
	class Src,
	class Dest
>
void
copy_and_convert_channel(
	Channel const &_channel,
	Src const &_src,
	Dest &_dest
)
{
	_dest.set(
		_channel,
		color::denormalize
		<
			typename Dest::format,
			Channel,
			Float
		>
		(
			_channel,
			color::normalize<
				Float
			>
			(
				_src,
				_channel
			)
		)
	);
}

}
}
}
}

#endif
