//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_HSVA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_HSVA_HPP_INCLUDED

#include <mizuiro/color/layout/cylindrical.hpp>
#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

typedef cylindrical<
	boost::mpl::vector4<
		channel::hue,
		channel::saturation,
		channel::value,
		channel::alpha
	>
> hsva;

}
}
}

#endif
