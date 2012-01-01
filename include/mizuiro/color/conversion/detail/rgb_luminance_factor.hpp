//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_RGB_LUMINANCE_FACTOR_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_RGB_LUMINANCE_FACTOR_HPP_INCLUDED

#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Ret
>
Ret
rgb_luminance_factor(
	mizuiro::color::channel::red const &
)
{
	return
		static_cast<
			Ret
		>(
			0.299
		);
}

template<
	typename Ret
>
Ret
rgb_luminance_factor(
	mizuiro::color::channel::green const &
)
{
	return
		static_cast<
			Ret
		>(
			0.587
		);
}

template<
	typename Ret
>
Ret
rgb_luminance_factor(
	mizuiro::color::channel::blue const &
)
{
	return
		static_cast<
			Ret
		>(
			0.114
		);
}

}
}
}
}

#endif
