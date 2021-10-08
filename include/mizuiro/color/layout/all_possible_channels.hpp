//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_LAYOUT_ALL_POSSIBLE_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_ALL_POSSIBLE_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/undefined.hpp>
#include <fcppt/mpl/set/object.hpp>
#include <fcppt/mpl/set/union.hpp>

namespace mizuiro::color::layout
{

template <typename Channels>
using all_possible_channels = fcppt::mpl::set::union_<
    fcppt::mpl::set::object<mizuiro::color::channel::alpha, mizuiro::color::channel::undefined>,
    Channels>;

}

#endif
