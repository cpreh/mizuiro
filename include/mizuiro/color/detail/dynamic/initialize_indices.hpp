//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_DETAIL_DYNAMIC_INITIALIZE_INDICES_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_DYNAMIC_INITIALIZE_INDICES_HPP_INCLUDED

#include <mizuiro/color/detail/dynamic/invalid_index.hpp>
#include <fcppt/array/init.hpp>

namespace mizuiro::color::detail::dynamic
{

template <typename ChannelIndexArray, typename Layout>
ChannelIndexArray initialize_indices(Layout const &_layout)
{
  ChannelIndexArray ret{fcppt::array::init<ChannelIndexArray>(
      [](auto) { return mizuiro::color::detail::dynamic::invalid_index(); })};

  // TODO(philipp) Static indices
  for (typename Layout::size_type index(0); index < _layout.size(); ++index)
  {
    // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index)
    ret.get_unsafe(static_cast<typename ChannelIndexArray::size_type>(
        // NOLINTNEXTLINE(cppcoreguidelines-pro-bounds-constant-array-index)
        _layout.get_unsafe(index).get())) = index;
  }

  return ret;
}

}

#endif
