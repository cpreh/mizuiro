//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_COLOR_NS_ACCESS_ADVANCE_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_COLOR_NS_ACCESS_ADVANCE_POINTER_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/color/access/advance_pointer.hpp>
#include <mizuiro/image/access/advance_pointer_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/to_color_store.hpp>
#include <mizuiro/image/format/color_ns/tag.hpp>
#include <mizuiro/image/format/color_ns/types/pointer.hpp>
#include <mizuiro/image/types/pointer.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace advance_pointer_ns
{

template<
	typename Access,
	typename ImageFormat,
	typename Constness
>
mizuiro::image::types::pointer<
	Access,
	ImageFormat,
	Constness
>
advance_pointer_adl(
	mizuiro::image::access::advance_pointer_ns::tag,
	mizuiro::image::format::color_ns::tag<
		ImageFormat
	>,
	Access,
	Constness,
	mizuiro::image::format::store<
		ImageFormat
	> const &_format,
	mizuiro::image::types::pointer<
		Access,
		ImageFormat,
		Constness
	> const _data,
	mizuiro::difference_type const _diff
)
{
	return
		mizuiro::color::access::advance_pointer<
			Access,
			Constness
		>(
			mizuiro::image::format::to_color_store(
				_format
			),
			_data,
			_diff
		);
}

}
}
}
}

#endif
