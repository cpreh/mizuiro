//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_DISABLE_GCC_WARNING_HPP_INCLUDED
#define MIZUIRO_DETAIL_DISABLE_GCC_WARNING_HPP_INCLUDED

#include <mizuiro/detail/compiler.hpp>


#if defined(MIZUIRO_DETAIL_GCC_COMPILER)
#	include <mizuiro/detail/disable_gcc_warning.hpp>
#	define MIZUIRO_DETAIL_DISABLE_GCC_WARNING(\
		warning\
	)\
	MIZUIRO_DETAIL_PRAGMA(\
		GCC diagnostic ignored #warning\
	)
#else
#	define MIZUIRO_DETAIL_DISABLE_GCC_WARNING(\
		warning\
	)
#endif

#endif
