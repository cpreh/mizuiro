//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_R_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_R_HPP_INCLUDED

#include <mizuiro/color/channel/red_fwd.hpp>
#include <mizuiro/color/space/r_fwd.hpp>
#include <mizuiro/mpl/list.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

struct r
{
	typedef
	mizuiro::mpl::list<
		mizuiro::color::channel::red
	>
	required_channels;
};

}
}
}

#endif
