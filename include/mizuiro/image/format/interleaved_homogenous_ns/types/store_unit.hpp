//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_HOMOGENOUS_NS_TYPES_STORE_UNIT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_HOMOGENOUS_NS_TYPES_STORE_UNIT_HPP_INCLUDED

#include <mizuiro/image/format/interleaved_homogenous_ns/tag.hpp>
#include <mizuiro/image/types/store_unit_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace types
{
namespace store_unit_ns
{

template<
	typename Format
>
typename
Format::color_format::channel_type
store_unit_adl(
	mizuiro::image::types::store_unit_ns::tag,
	mizuiro::image::format::interleaved_homogenous_ns::tag<
		Format
	>
);

}
}
}
}

#endif
