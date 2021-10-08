//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/color/format/heterogenous_static_fwd.hpp>
#include <fcppt/mpl/list/size.hpp>

namespace mizuiro::color::format
{

template <typename ChannelBits, typename Layout>
struct heterogenous_static
{
  static_assert(
      fcppt::mpl::list::size<ChannelBits>::value ==
          fcppt::mpl::list::size<typename Layout::channels>::value,
      "Number of channels doesn't match the layout");

  using channel_bits = ChannelBits;

  using layout = Layout;

  using channels = typename Layout::channels;
};

}

#endif
