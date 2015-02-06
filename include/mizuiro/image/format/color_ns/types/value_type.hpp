//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_COLOR_NS_TYPES_VALUE_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_COLOR_NS_TYPES_VALUE_TYPE_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/image/format/color_ns/tag.hpp>
#include <mizuiro/image/types/value_type_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace value_type_ns
{

template<
	typename ImageFormat
>
mizuiro::color::object<
	typename
	ImageFormat::color_format
>
value_type_adl(
	mizuiro::image::types::value_type_ns::tag,
	mizuiro::image::format::color_ns::tag<
		ImageFormat
	>
);

}
}
}
}

#endif
