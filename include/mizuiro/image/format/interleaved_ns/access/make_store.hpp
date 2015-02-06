//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_ACCESS_MAKE_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_ACCESS_MAKE_STORE_HPP_INCLUDED

#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/access/make_store_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/color_ns/access/stride.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>
#include <mizuiro/image/types/store.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace make_store_ns
{

template<
	typename Access,
	typename ImageFormat
>
mizuiro::image::types::store<
	Access,
	ImageFormat
>
make_store_adl(
	mizuiro::image::access::make_store_ns::tag,
	mizuiro::image::format::interleaved_ns::tag<
		ImageFormat
	>,
	Access,
	mizuiro::image::format::store<
		ImageFormat
	> const &_format,
	typename ImageFormat::dim const &_dim
)
{
	return
		mizuiro::image::types::store<
			Access,
			ImageFormat
		>(
			_dim.content()
			*
			mizuiro::image::access::stride<
				Access
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
