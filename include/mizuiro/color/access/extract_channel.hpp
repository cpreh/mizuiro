//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_ACCESS_EXTRACT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_EXTRACT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/extract_channel_ns/tag.hpp>
#include <mizuiro/color/format/make_tag_of.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/detail/assert_access.hpp>
#include <mizuiro/detail/assert_constness.hpp>

namespace mizuiro::color::access
{

template <typename Access, typename Constness, typename Format, typename Channel>
mizuiro::color::types::channel_reference<Access, Format, Channel, Constness> extract_channel(
    mizuiro::color::format::store<Format> const &_format_store,
    Channel const &_channel,
    mizuiro::color::types::pointer<Access, Format, Constness> const _data)
{
  MIZUIRO_DETAIL_ASSERT_ACCESS(Access);

  MIZUIRO_DETAIL_ASSERT_CONSTNESS(Constness);

  return extract_channel_adl(
      mizuiro::color::access::extract_channel_ns::tag(),
      Access(),
      mizuiro::color::format::make_tag_of<Format>(),
      _format_store,
      _channel,
      Constness(),
      _data);
}

}

#endif
