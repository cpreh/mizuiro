//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_RGB_TO_LUMINANCE_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_RGB_TO_LUMINANCE_HPP_INCLUDED

#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/luminance.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/object_impl.hpp>

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
	
	dest.set(
		channel::luminance(),
		color::denormalize<
			typename dest_type::format
		>(
			channel::luminance(),
			color::luminance(
				color::normalize<
					float
				>(
					_src,
					channel::red()
				),
				color::normalize<
					float
				>(
					_src,
					channel::green()
				),
				color::normalize<
					float
				>(
					_src,
					channel::blue()
				)
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
