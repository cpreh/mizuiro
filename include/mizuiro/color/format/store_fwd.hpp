//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_STORE_FWD_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STORE_FWD_HPP_INCLUDED

#include <mizuiro/color/format/detail/make.hpp>
#include <mizuiro/detail/format_store_fwd.hpp>

namespace mizuiro::color::format
{

template <typename Format>
using store = mizuiro::color::format::detail::make<Format, mizuiro::detail::format_store>;

}

#endif
