//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_NONASSIGNABLE_HPP_INCLUDED
#define MIZUIRO_DETAIL_NONASSIGNABLE_HPP_INCLUDED

#define MIZUIRO_DETAIL_NONASSIGNABLE(\
	classname_\
)\
private:\
	classname_ & \
	operator=(\
		classname_ const &\
	)

#endif
