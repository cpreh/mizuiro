//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_LUMINANCE_TO_RGB_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_LUMINANCE_TO_RGB_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/conversion/detail/rgb_luminance_factor.hpp>
#include <mizuiro/color/conversion/detail/set_channel_conditional.hpp>

namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Channel,
	typename Dest,
	typename Float
>
void
luminance_to_rgb_channel(
	Dest &_dest,
	Float const &_src_normalized
)
{
	mizuiro::color::conversion::detail::set_channel_conditional<
		Channel
	>(
		_dest,
		mizuiro::color::denormalize<
			typename Dest::format
		>
		(
			Channel(),
			mizuiro::color::conversion::detail::rgb_luminance_factor<
				Float
			>(
				Channel()
			)
			* _src_normalized
		)
	);
}

}
}
}
}

#endif
