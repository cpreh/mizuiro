//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_TAG_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_DETAIL_PLANAR_COLOR_NS_TAG_HPP_INCLUDED

#include <mizuiro/rebind_tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>

namespace mizuiro::image::format::detail::planar_color_ns
{

template <typename Format>
struct tag : mizuiro::rebind_tag<mizuiro::color::format::make_tag_of<typename Format::base>, Format>
{
};

}

#endif
