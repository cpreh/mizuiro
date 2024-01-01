//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_STATIC_NS_ACCESS_HAS_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STATIC_NS_ACCESS_HAS_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/has_channel_ns/tag.hpp>
#include <mizuiro/color/format/has_channel_static.hpp>
#include <mizuiro/color/format/store_fwd.hpp>
#include <mizuiro/color/format/static_ns/tag.hpp>
#include <mizuiro/color/format/static_ns/types/static_channels.hpp> // IWYU pragma: keep
#include <fcppt/type_traits/to_bool.hpp>

namespace mizuiro::color::access::has_channel_ns
{

template <typename Format, typename Channel>
inline constexpr bool has_channel_adl(
    mizuiro::color::access::has_channel_ns::tag,
    mizuiro::color::format::static_ns::tag<Format>,
    mizuiro::color::format::store<Format> const &,
    Channel const &)
{
  return fcppt::type_traits::to_bool<
      mizuiro::color::format::has_channel_static<Format, Channel>>::value;
}

}

#endif
