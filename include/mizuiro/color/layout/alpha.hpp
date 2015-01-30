//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_ALPHA_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/layout/make.hpp>
#include <mizuiro/color/space/empty.hpp>
#include <mizuiro/mpl/list.hpp>


namespace mizuiro
{
namespace color
{
namespace layout
{

typedef
mizuiro::color::layout::make<
	mizuiro::color::space::empty,
	mizuiro::mpl::list<
		mizuiro::color::channel::alpha
	>
>
alpha;

}
}
}

#endif
