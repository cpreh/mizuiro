//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_TEST_EXTERNAL_BEGIN_HPP_INCLUDED
#define MIZUIRO_TEST_EXTERNAL_BEGIN_HPP_INCLUDED



#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wold-style-cast"
#pragma GCC diagnostic ignored "-Woverloaded-virtual"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wundef"
#pragma GCC diagnostic ignored "-Wunused-variable"
#if defined(__clang__) || defined(__APPLE_CC__)
#pragma GCC diagnostic ignored "-Wdocumentation"
#else
#pragma GCC diagnostic ignored "-Wsuggest-override"
#endif
#endif

#else
#error "This header should not be included twice"
#endif
