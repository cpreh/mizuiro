//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_EXCLUDE_CHANNEL_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_EXCLUDE_CHANNEL_FUNCTION_HPP_INCLUDED

#include <mizuiro/color/access/compare_channels.hpp>
#include <mizuiro/color/format/store.hpp>

namespace mizuiro::color::conversion::detail
{

template <typename Format, typename StaticChannel>
class exclude_channel_function
{
public:
  using format_store = mizuiro::color::format::store<Format>;

  explicit exclude_channel_function(format_store const &_format) : format_(_format) {}

  template <typename OtherChannel>
  bool operator()(OtherChannel const &_channel) const
  {
    return !mizuiro::color::access::compare_channels<Format>(format_, StaticChannel(), _channel);
  }

private:
  format_store format_;
};

}

#endif
