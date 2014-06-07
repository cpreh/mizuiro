//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_STRIDE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_STRIDE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/access/stride.hpp>
#include <mizuiro/image/access/stride_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/to_color_store.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace stride_ns
{

template<
	typename Access,
	typename ImageFormat
>
mizuiro::size_type
stride_adl(
	mizuiro::image::access::stride_ns::tag,
	Access const &,
	mizuiro::image::format::interleaved_ns::tag<
		ImageFormat
	>,
	mizuiro::image::format::store<
		ImageFormat
	> const &_format
)
{
	return
		mizuiro::color::access::stride<
			Access
		>(
			mizuiro::image::format::to_color_store(
				_format
			)
		);
}

}
}
}
}

#endif
