//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_LUMINANCE_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_LUMINANCE_HPP_INCLUDED

#include <mizuiro/color/channel/luminance_fwd.hpp>
#include <fcppt/mpl/set/object.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

struct luminance
{
	using
	required_channels
	=
	fcppt::mpl::set::object<
		mizuiro::color::channel::luminance
	>;
};

}
}
}

#endif
