//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_TYPES_POINTER_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_HETEROGENOUS_NS_TYPES_POINTER_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>
#include <mizuiro/access/pointer.hpp>
#include <mizuiro/color/format/heterogenous_ns/tag.hpp>
#include <mizuiro/color/format/heterogenous_ns/types/store.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/color/types/pointer_ns/tag.hpp>

namespace mizuiro::color::types::pointer_ns
{

template <typename Access, typename Format, typename Constness>
mizuiro::
    apply_const<mizuiro::access::pointer<Access, mizuiro::color::types::store<Format> *>, Constness>
        pointer_adl(
            mizuiro::color::types::pointer_ns::tag,
            Access,
            mizuiro::color::format::heterogenous_ns::tag<Format>,
            Constness);

}

#endif
