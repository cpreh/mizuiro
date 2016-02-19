//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_PRAGMA_HPP_INCLUDED
#define MIZUIRO_DETAIL_PRAGMA_HPP_INCLUDED

#include <mizuiro/detail/compiler.hpp>


#if defined(MIZUIRO_DETAIL_GCC_COMPILER)
#define MIZUIRO_DETAIL_PRAGMA(x) _Pragma(#x)
#else
#error "Don't know what pragma should be!"
#endif

#endif
