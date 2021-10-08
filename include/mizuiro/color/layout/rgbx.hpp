//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_LAYOUT_RGBX_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_RGBX_HPP_INCLUDED

#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/undefined.hpp>
#include <mizuiro/color/layout/make.hpp>
#include <mizuiro/color/space/rgb.hpp>
#include <fcppt/mpl/list/object.hpp>

namespace mizuiro::color::layout
{

using rgbx = mizuiro::color::layout::make<
    mizuiro::color::space::rgb,
    fcppt::mpl::list::object<
        mizuiro::color::channel::red,
        mizuiro::color::channel::green,
        mizuiro::color::channel::blue,
        mizuiro::color::channel::undefined>>;

}

#endif
