//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_STORE_SIZE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_STORE_SIZE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/access/store_size_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/interleaved_ns/stride.hpp>
#include <mizuiro/image/format/interleaved_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace store_size_ns
{

template<
	typename Access,
	typename ImageFormat
>
mizuiro::size_type
store_size_adl(
	mizuiro::image::access::store_size_ns::tag,
	Access,
	mizuiro::image::format::interleaved_ns::tag<
		ImageFormat
	>,
	mizuiro::image::format::store<
		ImageFormat
	> const &_format,
	typename ImageFormat::dim const &_dim
)
{
	return
		_dim.content()
		*
		mizuiro::image::access::stride<
			Access
		>(
			_format
		);
}

}
}
}
}

#endif
