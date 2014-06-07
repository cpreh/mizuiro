//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_APPLY_CONST_RESULT_HPP_INCLUDED
#define MIZUIRO_APPLY_CONST_RESULT_HPP_INCLUDED

#include <mizuiro/apply_const.hpp>


namespace mizuiro
{

template<
	typename BaseType,
	typename Constness
>
using
apply_const_result
=
typename
mizuiro::apply_const<
	BaseType,
	Constness
>::type;

}

#endif
