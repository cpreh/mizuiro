//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_PROXY_IMPL_HPP_INCLUDED

#include <mizuiro/color/channel_proxy_decl.hpp>

template <typename Pointer, typename ValueType, typename ChannelAccess>
mizuiro::color::channel_proxy<Pointer, ValueType, ChannelAccess>::channel_proxy(pointer const _data)
    : data_(_data)
{
}

template <typename Pointer, typename ValueType, typename ChannelAccess>
mizuiro::color::channel_proxy<Pointer, ValueType, ChannelAccess> &
mizuiro::color::channel_proxy<Pointer, ValueType, ChannelAccess>::operator=(value_type const _ref)
{
  ChannelAccess::write(data_, _ref);

  return *this;
}

template <typename Pointer, typename ValueType, typename ChannelAccess>
typename mizuiro::color::channel_proxy<Pointer, ValueType, ChannelAccess>::value_type
mizuiro::color::channel_proxy<Pointer, ValueType, ChannelAccess>::get() const
{
  return ChannelAccess::read(data_);
}

template <typename Pointer, typename ValueType, typename ChannelAccess>
mizuiro::color::channel_proxy<Pointer, ValueType, ChannelAccess>::operator typename mizuiro::color::
    channel_proxy<Pointer, ValueType, ChannelAccess>::value_type() const
{
  return this->get();
}

#endif
