//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_ACCESS_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HAS_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/has_channel_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/detail/assert_channel.hpp>

namespace mizuiro::color::access
{

template <typename Format, typename Channel>
constexpr bool
has_channel(mizuiro::color::format::store<Format> const &_format, Channel const &_channel)
{
  MIZUIRO_COLOR_FORMAT_DETAIL_ASSERT_CHANNEL(Format, Channel);

  return has_channel_adl(
      mizuiro::color::access::has_channel_ns::tag(),
      mizuiro::color::format::make_tag_of<Format>(),
      _format,
      _channel);
}

}

#endif
