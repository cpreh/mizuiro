//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_ACCESS_EXTRACT_CHANNEL_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_ACCESS_EXTRACT_CHANNEL_NORMAL_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/access/channel_index.hpp>
#include <mizuiro/color/access/extract_channel_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>

namespace mizuiro::color::access::extract_channel_ns
{

template <typename Format, typename Channel, typename Constness>
inline mizuiro::color::types::channel_reference<mizuiro::access::normal, Format, Channel, Constness>
extract_channel_adl(
    mizuiro::color::access::extract_channel_ns::tag,
    mizuiro::access::normal,
    mizuiro::color::format::homogenous_ns::tag<Format>,
    mizuiro::color::format::store<Format> const &_format,
    Channel const &_channel,
    Constness const &,
    // NOLINTNEXTLINE(readability-avoid-const-params-in-decls)
    mizuiro::color::types::pointer<mizuiro::access::normal, Format, Constness> const _data)
{
  return _data[mizuiro::color::access::channel_index<Format>(_format, _channel)];
}

}

#endif
