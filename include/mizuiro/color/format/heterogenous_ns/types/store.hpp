//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_TYPES_STORE_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_TYPES_STORE_HPP_INCLUDED

#include <mizuiro/color/detail/heterogenous/bits.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/types/store_ns/tag.hpp>
#include <mizuiro/detail/uint_least.hpp>

namespace mizuiro::color::types::store_ns
{

template <typename Format>
mizuiro::detail::uint_least<
    mizuiro::color::detail::heterogenous::bits<typename Format::channel_bits>>
    store_adl(
        mizuiro::color::types::store_ns::tag, mizuiro::color::format::heterogenous_ns::tag<Format>);

}

#endif
