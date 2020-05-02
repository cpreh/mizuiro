//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_SRGB_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_SRGB_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/conversion/same_to_same_gamma.hpp>
#include <mizuiro/color/conversion/detail/srgb_gamma.hpp>
#include <mizuiro/color/format/argument.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{

template<
	typename Dest,
	typename Src
>
inline
mizuiro::color::object<
	Dest
>
srgb_to_rgb(
	Src const &_source,
	typename
	mizuiro::color::object<
		Dest
	>::format_store_type const &_format
		= mizuiro::color::format::argument<
			Dest
		>::get()
)
{
	return
		mizuiro::color::conversion::same_to_same_gamma<
			Dest
		>(
			_source,
			1.F
			/
			mizuiro::color::conversion::detail::srgb_gamma<
				// TODO(philipp): Choose a more appropriate type
				float
			>(),
			_format
		);
}

}
}
}

#endif
