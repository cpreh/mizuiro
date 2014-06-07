//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_OPTIONAL_DECL_HPP_INCLUDED
#define MIZUIRO_DETAIL_OPTIONAL_DECL_HPP_INCLUDED

#include <mizuiro/detail/optional_fwd.hpp>
#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/optional_decl.hpp>
#else
#include <mizuiro/detail/external_begin.hpp>
#include <boost/optional/optional.hpp>
#include <mizuiro/detail/external_end.hpp>
#endif

#endif
