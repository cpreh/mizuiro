//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_STORE_NORMAL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_STORE_NORMAL_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>
#include <mizuiro/image/raw_container_impl.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>
#include <mizuiro/image/types/store_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace store_ns
{

template<
	typename ImageFormat
>
mizuiro::image::raw_container<
	typename
	ImageFormat::color_format::channel_type
>
store_adl(
	mizuiro::image::types::store_ns::tag,
	mizuiro::access::normal,
	mizuiro::image::format::interleaved_ns::tag<
		ImageFormat
	>
);

}
}
}
}

#endif