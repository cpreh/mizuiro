//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_MAKE_TRAMPOLINE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_MAKE_TRAMPOLINE_HPP_INCLUDED

#include <mizuiro/color/init/trampoline.hpp>

#define MIZUIRO_COLOR_INIT_DETAIL_MAKE_TRAMPOLINE(\
	name\
)\
inline \
mizuiro::color::init::trampoline<\
	channel::name\
> const \
name() \
{ \
	return \
		mizuiro::color::init::trampoline< \
			channel::name\
		>();\
}

#endif
