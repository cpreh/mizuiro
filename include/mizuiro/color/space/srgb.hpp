//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_SRGB_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_SRGB_HPP_INCLUDED

#include <mizuiro/color/channel/blue_fwd.hpp>
#include <mizuiro/color/channel/green_fwd.hpp>
#include <mizuiro/color/channel/red_fwd.hpp>
#include <mizuiro/color/space/base.hpp>
#include <mizuiro/color/space/srgb_fwd.hpp>
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
struct srgb
:
mizuiro::color::space::base<
	Order,
	mizuiro::color::channel::red,
	mizuiro::color::channel::green,
	mizuiro::color::channel::blue
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
