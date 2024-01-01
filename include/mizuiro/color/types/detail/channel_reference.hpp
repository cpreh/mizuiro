//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_TYPES_DETAIL_CHANNEL_REFERENCE_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_DETAIL_CHANNEL_REFERENCE_HPP_INCLUDED

#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/detail/assert_channel.hpp>
#include <mizuiro/color/types/channel_reference_ns/tag.hpp>
#include <mizuiro/detail/assert_access.hpp>
#include <mizuiro/detail/assert_constness.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::color::types::detail
{

template <typename Access, typename Format, typename Channel, typename Constness>
struct channel_reference
{
  MIZUIRO_DETAIL_ASSERT_ACCESS(Access);

  MIZUIRO_DETAIL_ASSERT_CONSTNESS(Constness);

  MIZUIRO_COLOR_FORMAT_DETAIL_ASSERT_CHANNEL(Format, Channel);

  using type = decltype(channel_reference_adl(
      std::declval<mizuiro::color::types::channel_reference_ns::tag>(),
      std::declval<Access>(),
      mizuiro::color::format::make_tag_of<Format>(),
      std::declval<Channel>(),
      std::declval<Constness>()));
};

}

#endif
