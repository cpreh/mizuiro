//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_CAN_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_CAN_COPY_HPP_INCLUDED

#include <mizuiro/color/format/compatible.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>
#include <mizuiro/image/types/can_copy_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace can_copy_ns
{

template<
	typename ImageFormat1,
	typename ImageFormat2
>
mizuiro::color::format::compatible<
	typename
	ImageFormat1::color_format,
	typename
	ImageFormat2::color_format
>
can_copy_adl(
	mizuiro::image::types::can_copy_ns::tag,
	mizuiro::image::format::interleaved_ns::tag<
		ImageFormat1
	>,
	mizuiro::image::format::interleaved_ns::tag<
		ImageFormat2
	>
);

}
}
}
}

#endif
