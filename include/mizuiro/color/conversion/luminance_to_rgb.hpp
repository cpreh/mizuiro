//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_LUMINANCE_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_LUMINANCE_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/conversion/detail/luminance_to_rgb_channel.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{

template
<
	class Dest,
	class Src
>
color::object<
	Dest
> const
luminance_to_rgb(
	Src const &_src,
	typename color::object<
		Dest
	>::format_store_type const &_format
		= color::format_argument<Dest>::get()
)
{
	typedef color::object<
		Dest
	> dest_object;

	dest_object dest(
		_format
	);

	conversion::detail::copy_or_max_alpha(
		_src,
		dest
	);

	float const src_normalized =
		color::normalize
		<
			float
		>
		(
			_src,
			channel::luminance()
		);

	mizuiro::color::conversion::detail::luminance_to_rgb_channel<
		mizuiro::color::channel::red
	>(
		dest,
		src_normalized
	);

	mizuiro::color::conversion::detail::luminance_to_rgb_channel<
		mizuiro::color::channel::green
	>(
		dest,
		src_normalized
	);

	mizuiro::color::conversion::detail::luminance_to_rgb_channel<
		mizuiro::color::channel::blue
	>(
		dest,
		src_normalized
	);

	return dest;
}

}
}
}

#endif
