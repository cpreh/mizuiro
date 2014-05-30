//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_S_BGRA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_S_BGRA_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/layout/s_additive.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

typedef mizuiro::color::layout::s_additive<
	boost::mpl::vector4<
		mizuiro::color::channel::blue,
		mizuiro::color::channel::green,
		mizuiro::color::channel::red,
		mizuiro::color::channel::alpha
	>
> s_bgra;

}
}
}

#endif