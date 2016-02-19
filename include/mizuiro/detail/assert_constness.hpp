//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_ASSERT_CONSTNESS_HPP_INCLUDED
#define MIZUIRO_DETAIL_ASSERT_CONSTNESS_HPP_INCLUDED

#include <mizuiro/is_constness_tag.hpp>


#define MIZUIRO_DETAIL_ASSERT_CONSTNESS(\
	name\
)\
static_assert(\
	mizuiro::is_constness_tag<\
		name\
	>::value,\
	"Constness must be an constness tag type"\
)

#endif
