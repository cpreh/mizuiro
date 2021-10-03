//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_COLOR_NS_TYPES_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_COLOR_NS_TYPES_POINTER_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/image/format/color_ns/tag.hpp>
#include <mizuiro/image/types/pointer_ns/tag.hpp>


namespace mizuiro::image::types::pointer_ns
{

template<
	typename Access,
	typename ImageFormat,
	typename Constness
>
mizuiro::color::types::pointer<
	Access,
	typename
	ImageFormat::color_format,
	Constness
>
pointer_adl(
	mizuiro::image::types::pointer_ns::tag,
	Access,
	mizuiro::image::format::color_ns::tag<
		ImageFormat
	>,
	Constness
);

}

#endif
