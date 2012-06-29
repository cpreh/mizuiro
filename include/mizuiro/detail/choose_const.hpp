//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_CHOOSE_CONST_HPP_INCLUDED
#define MIZUIRO_DETAIL_CHOOSE_CONST_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename T
>
struct choose_const;

template<
	typename T
>
struct choose_const<
	T *
>
{
	typedef mizuiro::nonconst_tag type;
};

template<
	typename T
>
struct choose_const<
	T const *
>
{
	typedef mizuiro::const_tag type;
};

}
}

#endif
