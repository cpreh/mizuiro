//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_STATIC_TO_DYNAMIC_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_STATIC_TO_DYNAMIC_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/channel/tag.hpp>
#include <mizuiro/color/detail/dynamic/channel_index.hpp>
#include <fcppt/mpl/list/index_of.hpp>
#include <fcppt/mpl/set/to_list.hpp>

namespace mizuiro::color::detail::dynamic
{

template <typename Format, typename StaticChannel>
inline typename mizuiro::color::detail::dynamic::channel_index
static_to_dynamic_channel(mizuiro::color::channel::tag<StaticChannel> const &)
{
  return mizuiro::color::detail::dynamic::channel_index{fcppt::mpl::list::index_of<
      fcppt::mpl::set::to_list<typename Format::all_possible_channels>,
      StaticChannel>::value};
}

}

#endif
