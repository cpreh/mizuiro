//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_CHOOSE_CONST_HPP_INCLUDED
#define MIZUIRO_DETAIL_CHOOSE_CONST_HPP_INCLUDED

#include <mizuiro/const_tag_fwd.hpp>
#include <mizuiro/nonconst_tag_fwd.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Constness,
	typename NonConst,
	typename Const
>
struct choose_const;

template<
	typename NonConst,
	typename Const
>
struct choose_const<
	mizuiro::const_tag,
	NonConst,
	Const
>
{
	using
	type
	=
	Const;
};

template<
	typename NonConst,
	typename Const
>
struct choose_const<
	mizuiro::nonconst_tag,
	NonConst,
	Const
>
{
	using
	type
	=
	NonConst;
};

}
}

#endif
