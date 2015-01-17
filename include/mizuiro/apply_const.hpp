//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_APPLY_CONST_HPP_INCLUDED
#define MIZUIRO_APPLY_CONST_HPP_INCLUDED

#include <mizuiro/detail/apply_const.hpp>


namespace mizuiro
{

/**
\brief Applies const to references or pointers

Applies const to BaseType iff BaseType is a reference or a pointer and
Constness is mizuiro::const_tag.

\tparam Constness Must be either mizuiro::const_tag or mizuiro::nonconst_tag

\tparam BaseType Can be any type
*/
template<
	typename BaseType,
	typename Constness
>
using
apply_const
=
typename
mizuiro::detail::apply_const<
	BaseType,
	Constness
>::type;

}

#endif
