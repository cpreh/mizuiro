//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_EMPTY_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_EMPTY_HPP_INCLUDED

#include <mizuiro/color/space/empty_fwd.hpp>
#include <mizuiro/mpl/list.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

struct empty
{
	typedef
	mizuiro::mpl::list<>
	required_channels;
};

}
}
}

#endif
