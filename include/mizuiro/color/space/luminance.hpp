//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_SPACE_LUMINANCE_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_LUMINANCE_HPP_INCLUDED

#include <mizuiro/color/channel/luminance_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/sequences/set.hpp>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace space
{

struct luminance
{
	typedef
	brigand::set<
		mizuiro::color::channel::luminance
	>
	required_channels;
};

}
}
}

#endif
