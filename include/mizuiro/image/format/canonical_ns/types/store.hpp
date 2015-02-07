//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_CANONICAL_NS_TYPES_STORE_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>
#include <mizuiro/image/format/canonical_ns/tag.hpp>
#include <mizuiro/image/types/store_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <vector>
#include <mizuiro/detail/external_end.hpp>


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
std::vector<
	typename
	ImageFormat::element_type
>
store_adl(
	mizuiro::image::types::store_ns::tag,
	mizuiro::access::normal,
	mizuiro::image::format::canonical_ns::tag<
		ImageFormat
	>
);

}
}
}
}

#endif
