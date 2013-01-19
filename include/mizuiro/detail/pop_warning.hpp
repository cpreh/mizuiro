//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_POP_WARNING_HPP_INCLUDED
#define MIZUIRO_DETAIL_POP_WARNING_HPP_INCLUDED

#include <mizuiro/config.hpp>

#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/preprocessor/pop_warning.hpp>
#define MIZUIRO_DETAIL_POP_WARNING FCPPT_PP_POP_WARNING
#else
#define MIZUIRO_DETAIL_POP_WARNING
#endif

#endif
