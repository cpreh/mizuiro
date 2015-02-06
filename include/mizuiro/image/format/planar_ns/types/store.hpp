//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_NS_TYPES_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_NS_TYPES_STORE_HPP_INCLUDED

#include <mizuiro/array.hpp>
#include <mizuiro/access/store_unit.hpp>
#include <mizuiro/color/types/store_unit.hpp>
#include <mizuiro/image/raw_container_impl.hpp>
#include <mizuiro/image/format/planar_ns/tag.hpp>
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
	typename Access,
	typename ImageFormat
>
mizuiro::array<
	mizuiro::image::raw_container<
		mizuiro::access::store_unit<
			Access,
			mizuiro::color::types::store_unit<
				typename
				ImageFormat::color_format
			>
		>
	>,
	ImageFormat::element_count
>
store_adl(
	mizuiro::image::types::store_ns::tag,
	Access,
	mizuiro::image::format::planar_ns::tag<
		ImageFormat
	>
);

}
}
}
}

#endif
