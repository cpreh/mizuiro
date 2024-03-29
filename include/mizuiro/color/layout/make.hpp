//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_LAYOUT_MAKE_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_MAKE_HPP_INCLUDED

#include <mizuiro/color/layout/all_possible_channels.hpp>
#include <mizuiro/color/layout/detail/has_all_channels.hpp>
#include <fcppt/mpl/list/size.hpp>
#include <fcppt/mpl/set/to_list.hpp>

namespace mizuiro::color::layout
{

/**
\brief A typedef helper class used to define color spaces

A color space consists of possible channels (e.g. red, green, blue), possibly
including alpha channels (to include transparency which is not part of the
traditional color space definition) or undefined channels (which are purely
used as an efficient data representation mechanism). Alpha channels will never
contribute 'color' while undefined channels will be ignored.

\tparam Space A color space

\tparam Channels An mpl::list::object consisting of \link color_channel Color
Channels\endlink
*/
template <typename Space, typename Channels>
struct make
{
  using space = Space;

  using channels = Channels;

  static_assert(
      mizuiro::color::layout::detail::has_all_channels<
          channels,
          fcppt::mpl::set::to_list<mizuiro::color::layout::all_possible_channels<
              typename Space::required_channels>>>::value,
      "Invalid color channel which is not part of the color space");

  static_assert(
      fcppt::mpl::list::size<fcppt::mpl::set::to_list<typename Space::required_channels>>::value <=
          3,
      "A color space shouldn't have more than three channels");

  static_assert(
      mizuiro::color::layout::detail::has_all_channels<
          fcppt::mpl::set::to_list<typename Space::required_channels>,
          channels>::value,
      "Missing color channel in color space");
};

}

#endif
