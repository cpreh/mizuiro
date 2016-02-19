//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_COLOR_NS_TYPES_NEEDS_PREPARE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_COLOR_NS_TYPES_NEEDS_PREPARE_HPP_INCLUDED

#include <mizuiro/color/types/store_needs_init.hpp>
#include <mizuiro/image/format/color_ns/tag.hpp>
#include <mizuiro/image/types/needs_prepare_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace needs_prepare_ns
{

template<
	typename ImageFormat
>
mizuiro::color::types::store_needs_init<
	typename
	ImageFormat::color_format
>
needs_prepare_adl(
	mizuiro::image::types::needs_prepare_ns::tag,
	mizuiro::image::format::color_ns::tag<
		ImageFormat
	>
);

}
}
}
}

#endif
