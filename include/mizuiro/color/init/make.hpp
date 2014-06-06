//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_MAKE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_MAKE_HPP_INCLUDED

#include <mizuiro/color/init/detail/trampoline.hpp>


#define MIZUIRO_COLOR_INIT_MAKE(\
	ns,\
	name\
)\
inline \
mizuiro::color::init::detail::trampoline<\
	ns::name\
> const \
name() \
{ \
	return \
		mizuiro::color::init::detail::trampoline< \
			ns::name\
		>();\
}

#endif
