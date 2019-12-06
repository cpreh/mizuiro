//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_SRGB_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_SRGB_HPP_INCLUDED

#include <fcppt/metal/set/make.hpp>
#include <mizuiro/color/channel/blue_fwd.hpp>
#include <mizuiro/color/channel/green_fwd.hpp>
#include <mizuiro/color/channel/red_fwd.hpp>
#include <mizuiro/color/space/srgb_fwd.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

struct srgb
{
	typedef
	fcppt::metal::set::make<
		mizuiro::color::channel::red,
		mizuiro::color::channel::green,
		mizuiro::color::channel::blue
	>
	required_channels;
};

}
}
}

#endif
