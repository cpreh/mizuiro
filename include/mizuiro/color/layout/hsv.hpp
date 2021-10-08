//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_LAYOUT_HSV_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_HSV_HPP_INCLUDED

#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/color/layout/make.hpp>
#include <mizuiro/color/space/hsv.hpp>
#include <fcppt/mpl/list/object.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

using hsv = mizuiro::color::layout::make<
    mizuiro::color::space::hsv,
    fcppt::mpl::list::object<
        mizuiro::color::channel::hue,
        mizuiro::color::channel::saturation,
        mizuiro::color::channel::value>>;

}
}
}

#endif
