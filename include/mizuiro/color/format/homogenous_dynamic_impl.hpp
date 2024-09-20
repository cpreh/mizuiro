//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_DYNAMIC_IMPL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/detail/dynamic/initialize_indices.hpp>
#include <mizuiro/color/detail/dynamic/make_channels.hpp>
#include <mizuiro/color/format/homogenous_dynamic_decl.hpp> // IWYU pragma: export
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

template <typename ChannelType, typename Space, mizuiro::size_type ChannelCount>
template <typename Layout>
mizuiro::color::format::homogenous_dynamic<ChannelType, Space, ChannelCount>::homogenous_dynamic(
    Layout const &)
    : channels(mizuiro::color::detail::dynamic::
                   make_channels<all_possible_channels, typename Layout::channels>()),
      indices(mizuiro::color::detail::dynamic::initialize_indices<channel_index_array>(channels))
{
  static_assert(std::is_same_v<Space, typename Layout::space>, "Color spaces must match");
}

#endif
