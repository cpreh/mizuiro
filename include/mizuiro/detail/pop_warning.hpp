//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_POP_WARNING_HPP_INCLUDED
#define MIZUIRO_DETAIL_POP_WARNING_HPP_INCLUDED

#include <mizuiro/detail/compiler.hpp>


#if defined(MIZUIRO_DETAIL_GCC_COMPILER)
#include <mizuiro/detail/pragma.hpp>
#define MIZUIRO_DETAIL_POP_WARNING MIZUIRO_DETAIL_PRAGMA(GCC diagnostic pop)
#else
#define MIZUIRO_DETAIL_POP_WARNING
#endif

#endif
