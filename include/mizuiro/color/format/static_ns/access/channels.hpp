//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_ACCESS_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_ACCESS_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/access/channels_ns/tag.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/static_ns/tag.hpp>

namespace mizuiro::color::access::channels_ns
{

template <typename Format>
constexpr Format::channels channels_adl(
    mizuiro::color::access::channels_ns::tag,
    mizuiro::color::format::static_ns::tag<Format>,
    mizuiro::color::format::store<Format> const &)
{
  return typename Format::channels{};
}

}

#endif
