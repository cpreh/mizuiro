#ifndef MIZUIRO_COLOR_INIT_DETAIL_MAKE_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_MAKE_HPP_INCLUDED

#include <mizuiro/color/init/detail/trampoline.hpp>

#define MIZUIRO_COLOR_INIT_DETAIL_MAKE(name)\
detail::trampoline<\
	channel::name\
> const name((\
	detail::trampoline<\
		channel::name\
	>()\
));

#endif
