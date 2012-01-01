//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_RGB_TO_LUMINANCE_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_RGB_TO_LUMINANCE_HPP_INCLUDED

#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/conversion/detail/extract_luminance_part.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{

template
<
	typename Dest,
	typename Src
>
color::object<
	Dest
> const
rgb_to_luminance(
	Src const &_src,
	typename color::object<
		Dest
	>::format_store_type const &_format
		= color::format_argument<Dest>::get()
)
{
	typedef color::object<
		Dest
	> dest_type;

	dest_type dest(
		_format
	);

	typedef float intermediate_type;

	dest.set(
		channel::luminance(),
		color::denormalize<
			typename dest_type::format
		>(
			channel::luminance(),
			color::conversion::detail::extract_luminance_part<
				channel::red,
				intermediate_type
			>(
				_src
			)
			+
			color::conversion::detail::extract_luminance_part<
				channel::green,
				intermediate_type
			>(
				_src
			)
			+
			color::conversion::detail::extract_luminance_part<
				channel::blue,
				intermediate_type
			>(
				_src
			)
		)
	);

	conversion::detail::copy_or_max_alpha(
		_src,
		dest
	);

	return dest;
}

}
}
}

#endif
