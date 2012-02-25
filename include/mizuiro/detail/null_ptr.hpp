//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_NULL_PTR_HPP_INCLUDED
#define MIZUIRO_DETAIL_NULL_PTR_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/null_ptr.hpp>
#include <fcppt/null_ptr_t.hpp>
#else
#include <mizuiro/detail/null_ptr_t.hpp>
#endif

namespace mizuiro
{
namespace detail
{

#ifdef MIZUIRO_HAVE_FCPPT
inline
fcppt::null_ptr_t const
null_ptr()
{
	return fcppt::null_ptr();
}
#else
inline
mizuiro::detail::null_ptr_t const
null_ptr()
{
	return mizuiro::detail::null_ptr_t();
}
#endif

}
}

#endif
