//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_APPLY_CONST_HPP_INCLUDED
#define MIZUIRO_DETAIL_APPLY_CONST_HPP_INCLUDED

#include <mizuiro/const_tag_fwd.hpp>
#include <mizuiro/nonconst_tag_fwd.hpp>


namespace mizuiro
{
namespace detail
{

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
}

#endif
