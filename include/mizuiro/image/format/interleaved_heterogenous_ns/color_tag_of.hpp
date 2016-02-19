//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_HETEROGENOUS_NS_COLOR_TAG_OF_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_HETEROGENOUS_NS_COLOR_TAG_OF_HPP_INCLUDED

#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/image/format/interleaved_heterogenous_ns/tag.hpp>
#include <mizuiro/image/format/interleaved_ns/color_tag_of_ns/tag.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{
namespace interleaved_ns
{
namespace color_tag_of_ns
{

template<
	typename Type
>
mizuiro::image::format::interleaved_heterogenous_ns::tag<
	Type
>
color_tag_of_adl(
	mizuiro::image::format::interleaved_ns::color_tag_of_ns::tag,
	mizuiro::color::format::heterogenous_ns::tag<
		Type
	>
);

}
}
}
}
}

#endif
