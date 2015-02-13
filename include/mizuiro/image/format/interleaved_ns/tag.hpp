//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_TAG_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_INTERLEAVED_NS_TAG_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/format/color_ns/tag.hpp>
#include <mizuiro/image/format/interleaved_ns/make_color_tag_of.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{
namespace interleaved_ns
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct tag
:
mizuiro::image::format::interleaved_ns::make_color_tag_of<
	Format
>,
mizuiro::image::format::color_ns::tag<
	Format
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}
}

#endif
