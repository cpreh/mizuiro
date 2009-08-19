#ifndef MIZUIRO_DETAIL_UNLIKELY_HPP_INCLUDED
#define MIZUIRO_DETAIL_UNLIKELY_HPP_INCLUDED

#include <mizuiro/config.hpp>

#if defined(MIZUIRO_HAVE_BUILTIN_EXPECT)
#define MIZUIRO_DETAIL_UNLIKELY(x) __builtin_expect((x), 0)
#else
#define MIZUIRO_DETAIL_UNLIKELY(x)
#endif

#endif
