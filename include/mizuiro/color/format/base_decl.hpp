//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/color/format/detail/make.hpp>
#include <mizuiro/detail/format_base_decl.hpp> // IWYU pragma: keep

namespace mizuiro::color::format
{

template <typename Format>
using base = mizuiro::color::format::detail::make<Format, mizuiro::detail::format_base>;

}

#endif
