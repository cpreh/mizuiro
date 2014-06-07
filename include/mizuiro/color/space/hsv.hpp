//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_HSV_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_HSV_HPP_INCLUDED

#include <mizuiro/color/channel/hue_fwd.hpp>
#include <mizuiro/color/channel/saturation_fwd.hpp>
#include <mizuiro/color/channel/value_fwd.hpp>
#include <mizuiro/color/space/base.hpp>
#include <mizuiro/color/space/hsv_fwd.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Order
>
struct hsv
:
mizuiro::color::space::base<
	Order,
	mizuiro::color::channel::hue,
	mizuiro::color::channel::saturation,
	mizuiro::color::channel::value
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
