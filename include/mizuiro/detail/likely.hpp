#ifndef MIZUIRO_DETAIL_LIKELY_HPP_INCLUDED
#define MIZUIRO_DETAIL_LIKELY_HPP_INCLUDED

#include <mizuiro/config.hpp>

#if defined(MIZUIRO_HAVE_BUILTIN_EXPECT)
#define MIZUIRO_DETAIL_LIKELY(x) __builtin_expect((x), 1)
#else
#define MIZUIRO_DETAIL_LIKELY(x)
#endif

#endif
