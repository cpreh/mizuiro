//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_S_RGBA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_S_RGBA_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/layout/make.hpp>
#include <mizuiro/color/space/srgb.hpp>
#include <fcppt/mpl/list/object.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

using
s_rgba
=
mizuiro::color::layout::make<
	mizuiro::color::space::srgb,
	fcppt::mpl::list::object<
		mizuiro::color::channel::red,
		mizuiro::color::channel::green,
		mizuiro::color::channel::blue,
		mizuiro::color::channel::alpha
	>
>;

}
}
}

#endif
