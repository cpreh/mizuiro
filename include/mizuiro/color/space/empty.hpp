//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_SPACE_EMPTY_HPP_INCLUDED
#define MIZUIRO_COLOR_SPACE_EMPTY_HPP_INCLUDED

#include <mizuiro/color/space/empty_fwd.hpp> // IWYU pragma: keep
#include <fcppt/mpl/set/object.hpp>

namespace mizuiro::color::space
{

struct empty
{
  using required_channels = fcppt::mpl::set::object<>;
};

}

#endif
