//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_TYPES_CHANNEL_REFERENCE_NORMAL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HOMOGENOUS_NS_TYPES_CHANNEL_REFERENCE_NORMAL_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/format/homogenous_ns/tag.hpp>
#include <mizuiro/color/types/channel_reference_ns/tag.hpp>

namespace mizuiro::color::types::channel_reference_ns
{

template <typename Format, typename Channel, typename Constness>
mizuiro::apply_const<typename Format::channel_type &, Constness> channel_reference_adl(
    mizuiro::color::types::channel_reference_ns::tag,
    mizuiro::access::normal,
    mizuiro::color::format::homogenous_ns::tag<Format>,
    Channel,
    Constness);

}

#endif
