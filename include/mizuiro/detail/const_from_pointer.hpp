//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_CONST_FROM_POINTER_HPP_INCLUDED
#define MIZUIRO_DETAIL_CONST_FROM_POINTER_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename T
>
struct const_from_pointer;

template<
	typename T
>
struct const_from_pointer<
	T *
>
{
	using
	type
	=
	mizuiro::nonconst_tag;
};

template<
	typename T
>
struct const_from_pointer<
	T const *
>
{
	using
	type
	=
	mizuiro::const_tag;
};

}
}

#endif
