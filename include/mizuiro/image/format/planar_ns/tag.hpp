//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_IMAGE_FORMAT_PLANAR_NS_TAG_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_PLANAR_NS_TAG_HPP_INCLUDED

#include <mizuiro/image/format/color_ns/tag.hpp>

namespace mizuiro::image::format::planar_ns
{

template <typename Format>
struct tag : mizuiro::image::format::color_ns::tag<Format>
{
};

}

#endif
