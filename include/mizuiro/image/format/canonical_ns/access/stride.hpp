//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_ACCESS_STRIDE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_ACCESS_STRIDE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/image/access/stride_ns/tag.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/canonical_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{
namespace stride_ns
{

template<
	typename ImageFormat
>
mizuiro::size_type
stride_adl(
	mizuiro::image::access::stride_ns::tag,
	mizuiro::access::normal,
	mizuiro::image::format::canonical_ns::tag<
		ImageFormat
	>,
	mizuiro::image::format::store<
		ImageFormat
	> const &
)
{
	return
		1u;
}

}
}
}
}

#endif
