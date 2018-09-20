//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_HSVA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_HSVA_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/color/layout/make.hpp>
#include <mizuiro/color/space/hsv.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/list.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

typedef
mizuiro::color::layout::make<
	mizuiro::color::space::hsv,
	brigand::list<
		mizuiro::color::channel::hue,
		mizuiro::color::channel::saturation,
		mizuiro::color::channel::value,
		mizuiro::color::channel::alpha
	>
>
hsva;

}
}
}

#endif
