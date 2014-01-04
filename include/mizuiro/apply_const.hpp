//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_APPLY_CONST_HPP_INCLUDED
#define MIZUIRO_APPLY_CONST_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>


namespace mizuiro
{

/**
\brief Applies const to references or pointers

Applies const to BaseType iff BaseType is a reference or a pointer and
Constness is mizuiro::const_tag. Use <code>apply_const<BaseType,
Constness>::type</code> to access the result.

\tparam Constness Must be either mizuiro::const_tag or mizuiro::nonconst_tag

\tparam BaseType Can be any type
*/
template<
	typename BaseType,
	typename Constness
>
struct apply_const;

template<
	typename BaseType
>
struct apply_const<
	BaseType,
	mizuiro::const_tag
>;

template<
	typename BaseType
>
struct apply_const<
	BaseType &,
	mizuiro::const_tag
>
{
	typedef BaseType const &type;
};

template<
	typename BaseType
>
struct apply_const<
	BaseType *,
	mizuiro::const_tag
>
{
	typedef BaseType const *type;
};

template<
	typename BaseType
>
struct apply_const<
	BaseType,
	mizuiro::nonconst_tag
>
{
	typedef BaseType type;
};

}

#endif
