//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_CHANNEL_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/color/channel_proxy_fwd.hpp>

namespace mizuiro::color
{

template <typename Pointer, typename ValueType, typename ChannelAccess>
class channel_proxy
{
public:
  using value_type = ValueType;

  using pointer = Pointer;

  using channel_access = ChannelAccess;

  explicit channel_proxy(pointer data);

  channel_proxy &operator=(value_type);

  [[nodiscard]] value_type get() const;

  // NOLINTNEXTLINE(google-explicit-constructor,hicpp-explicit-conversions)
  operator value_type() const;

private:
  pointer data_;
};

}

#endif
