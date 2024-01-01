//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DECLTYPE_HPP_INCLUDED
#define MIZUIRO_DECLTYPE_HPP_INCLUDED

#include <mizuiro/detail/decltype_use.hpp> // IWYU pragma: keep

#define MIZUIRO_DECLTYPE(expr) decltype(mizuiro::detail::decltype_use(expr))

#endif
