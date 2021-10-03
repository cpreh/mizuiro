//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_SRGB_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_SRGB_HPP_INCLUDED

#include <mizuiro/color/channel/blue_fwd.hpp>
#include <mizuiro/color/channel/green_fwd.hpp>
#include <mizuiro/color/channel/red_fwd.hpp>
#include <mizuiro/color/space/srgb_fwd.hpp>
#include <fcppt/mpl/set/object.hpp>


namespace mizuiro::color::space
{

struct srgb
{
	using
	required_channels
	=
	fcppt::mpl::set::object<
		mizuiro::color::channel::red,
		mizuiro::color::channel::green,
		mizuiro::color::channel::blue
	>;
};

}

#endif
