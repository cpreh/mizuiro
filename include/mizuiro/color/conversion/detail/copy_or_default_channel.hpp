//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_DEFAULT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_DEFAULT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/format/definitely_has_channel.hpp>
#include <mizuiro/color/format/definitely_has_not_channel.hpp>
#include <mizuiro/color/format/might_have_channel.hpp>

namespace mizuiro::color::conversion::detail
{

template <typename Converter, typename DefaultAction, typename Channel, typename Src, typename Dest>
inline void copy_or_default_channel(
    Converter const &_converter,
    DefaultAction const &,
    Channel const &_channel,
    Src const &_src,
    Dest &_dest)
  requires(
      mizuiro::color::format::definitely_has_channel<typename Src::format, Channel>::value &&
      mizuiro::color::format::definitely_has_channel<typename Dest::format, Channel>::value)
{
  _converter(_channel, _src, _dest);
}

template <typename Converter, typename DefaultAction, typename Channel, typename Src, typename Dest>
inline void copy_or_default_channel(
    Converter const &,
    DefaultAction const &_default_action,
    Channel const &_channel,
    Src const &,
    Dest &)
  requires(
      mizuiro::color::format::definitely_has_not_channel<typename Src::format, Channel>::value &&
      mizuiro::color::format::definitely_has_channel<typename Dest::format, Channel>::value)
{
  _default_action(_channel);
}

template <typename Converter, typename DefaultAction, typename Channel, typename Src, typename Dest>
inline void copy_or_default_channel(
    Converter const &_converter,
    DefaultAction const &_default_action,
    Channel const &_channel,
    Src const &_src,
    Dest &_dest)
  requires(
      mizuiro::color::format::might_have_channel<typename Src::format, Channel>::value &&
      mizuiro::color::format::definitely_has_channel<typename Dest::format, Channel>::value)
{
  if (mizuiro::color::access::has_channel<typename Src::format>(_src.format_store(), _channel))
  {
    _converter(_channel, _src, _dest);
  }
  else
  {
    _default_action(_channel);
  }
}

template <typename Converter, typename DefaultAction, typename Channel, typename Src, typename Dest>
inline void copy_or_default_channel(
    Converter const &, DefaultAction const &, Channel const &, Src const &, Dest &)
  requires(
      mizuiro::color::format::definitely_has_not_channel<typename Dest::format, Channel>::value)
{
}

template <typename Converter, typename DefaultAction, typename Channel, typename Src, typename Dest>
inline void copy_or_default_channel(
    Converter const &_converter,
    DefaultAction const &,
    Channel const &_channel,
    Src const &_src,
    Dest &_dest)
  requires(
      mizuiro::color::format::definitely_has_channel<typename Src::format, Channel>::value &&
      mizuiro::color::format::might_have_channel<typename Dest::format, Channel>::value)
{
  if (mizuiro::color::access::has_channel<typename Dest::format>(_dest.format_store(), _channel))
  {
    _converter(_channel, _src, _dest);
  }
}

template <typename Converter, typename DefaultAction, typename Channel, typename Src, typename Dest>
inline void copy_or_default_channel(
    Converter const &,
    DefaultAction const &_default_action,
    Channel const &_channel,
    Src const &,
    Dest &_dest)
  requires(
      mizuiro::color::format::definitely_has_not_channel<typename Src::format, Channel>::value &&
      mizuiro::color::format::might_have_channel<typename Dest::format, Channel>::value)
{
  if (mizuiro::color::access::has_channel<typename Dest::format>(_dest.format_store(), _channel))
  {
    _default_action(_channel);
  }
}

template <typename Converter, typename DefaultAction, typename Channel, typename Src, typename Dest>
inline void copy_or_default_channel(
    Converter const &_converter,
    DefaultAction const &_default_action,
    Channel const &_channel,
    Src const &_src,
    Dest &_dest)
  requires(
      mizuiro::color::format::might_have_channel<typename Src::format, Channel>::value &&
      mizuiro::color::format::might_have_channel<typename Dest::format, Channel>::value)
{
  if (!mizuiro::color::access::has_channel<typename Dest::format>(_dest.format_store(), _channel))
  {
    return;
  }

  if (mizuiro::color::access::has_channel<typename Src::format>(_src.format_store(), _channel))
  {
    _converter(_channel, _src, _dest);
  }
  else
  {
    _default_action(_channel);
  }
}
}

#endif
