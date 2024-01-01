//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_TYPES_DETAIL_CHANNEL_VALUE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_DETAIL_CHANNEL_VALUE_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/detail/assert_channel.hpp>
#include <mizuiro/color/types/channel_value_ns/tag.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::types::detail
{

template <typename Format, typename Channel>
struct channel_value
{
  MIZUIRO_COLOR_FORMAT_DETAIL_ASSERT_CHANNEL(Format, Channel);

  using type = decltype(channel_value_adl(
      std::declval<mizuiro::color::types::channel_value_ns::tag>(),
      mizuiro::color::format::make_tag_of<Format>(),
      std::declval<Channel>()));
};

}

#endif
