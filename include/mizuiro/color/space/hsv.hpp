//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_HSV_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_HSV_HPP_INCLUDED

#include <mizuiro/color/channel/hue_fwd.hpp>
#include <mizuiro/color/channel/saturation_fwd.hpp>
#include <mizuiro/color/channel/value_fwd.hpp>
#include <mizuiro/color/space/hsv_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/set.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

struct hsv
{
	typedef
	brigand::set<
		mizuiro::color::channel::hue,
		mizuiro::color::channel::saturation,
		mizuiro::color::channel::value
	>
	required_channels;
};

}
}
}

#endif
