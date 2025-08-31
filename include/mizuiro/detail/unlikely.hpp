//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef MIZUIRO_DETAIL_UNLIKELY_HPP_INCLUDED
#define MIZUIRO_DETAIL_UNLIKELY_HPP_INCLUDED

#ifdef __GNUC__
#define MIZUIRO_DETAIL_UNLIKELY(x) __builtin_expect((x), 0)
#else
#define MIZUIRO_DETAIL_UNLIKELY(x) (x)
#endif

#endif
