//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_CAN_COPY_IN_PLACE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_CAN_COPY_IN_PLACE_HPP_INCLUDED

#include <mizuiro/color/types/static_channels.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>
#include <mizuiro/image/types/can_copy_in_place_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace can_copy_in_place_ns
{

template<
	typename ImageFormat1,
	typename ImageFormat2
>
std::is_same<
	mizuiro::color::types::static_channels<
		typename
		ImageFormat1::color_format
	>,
	mizuiro::color::types::static_channels<
		typename
		ImageFormat2::color_format
	>
>
can_copy_in_place_adl(
	mizuiro::image::types::can_copy_in_place_ns::tag,
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
