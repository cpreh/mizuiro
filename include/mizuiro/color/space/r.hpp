//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_R_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_R_HPP_INCLUDED

#include <mizuiro/color/channel/red_fwd.hpp>
#include <mizuiro/color/space/base.hpp>
#include <mizuiro/color/space/r_fwd.hpp>
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
struct r
:
mizuiro::color::space::base<
	Order,
	mizuiro::color::channel::red
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
