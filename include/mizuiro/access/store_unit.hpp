//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_ACCESS_STORE_UNIT_HPP_INCLUDED
#define MIZUIRO_ACCESS_STORE_UNIT_HPP_INCLUDED

#include <mizuiro/raw_value.hpp>
#include <mizuiro/access/raw_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>

namespace mizuiro::access
{

template <typename Access, typename Normal>
using store_unit =
    std::conditional_t<std::is_same_v<Access, mizuiro::access::raw>, mizuiro::raw_value, Normal>;
}

#endif
