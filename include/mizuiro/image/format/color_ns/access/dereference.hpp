//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_COLOR_NS_ACCESS_DEREFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_COLOR_NS_ACCESS_DEREFERENCE_HPP_INCLUDED

#include <mizuiro/image/access/dereference_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/to_color_store.hpp>
#include <mizuiro/image/format/color_ns/tag.hpp>
#include <mizuiro/image/format/color_ns/types/pointer.hpp>
#include <mizuiro/image/format/color_ns/types/reference.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace dereference_ns
{

template<
	typename Access,
	typename ImageFormat,
	typename Constness
>
mizuiro::image::types::reference<
	Access,
	ImageFormat,
	Constness
>
dereference_adl(
	mizuiro::image::access::dereference_ns::tag,
	Access const &,
	mizuiro::image::format::color_ns::tag<
		ImageFormat
	>,
	Constness,
	mizuiro::image::format::store<
		ImageFormat
	> const &_format,
	mizuiro::image::types::pointer<
		Access,
		ImageFormat,
		Constness
	> const _data
)
{
	return
		mizuiro::image::types::reference<
			Access,
			ImageFormat,
			Constness
		>(
			_data,
			mizuiro::image::format::to_color_store<
				ImageFormat
			>(
				_format
			)
		);
}

}
}
}
}

#endif
