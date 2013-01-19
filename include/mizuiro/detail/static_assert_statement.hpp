//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_STATIC_ASSERT_STATEMENT_HPP_INCLUDED
#define MIZUIRO_DETAIL_STATIC_ASSERT_STATEMENT_HPP_INCLUDED

#include <mizuiro/config.hpp>

#if defined(MIZUIRO_HAVE_FCPPT)

#define MIZUIRO_DETAIL_STATIC_ASSERT_STATEMENT(\
	cond\
)\
static_assert(\
	cond,\
	""\
)

#else

#include <mizuiro/detail/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <mizuiro/detail/external_end.hpp>

#define MIZUIRO_DETAIL_STATIC_ASSERT_STATEMENT(\
	cond\
)\
BOOST_STATIC_ASSERT(\
	cond\
)

#endif

#endif
