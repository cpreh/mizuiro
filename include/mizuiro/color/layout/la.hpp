//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_LA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_LA_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/layout/luminance.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

typedef layout::luminance<
	boost::mpl::vector2<
		channel::luminance,
		channel::alpha
	>
> la;

}
}
}

#endif
