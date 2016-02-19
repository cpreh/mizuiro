//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_POINTER_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_POINTER_HPP_INCLUDED

#include <mizuiro/color/types/detail/pointer.hpp>


namespace mizuiro
{
namespace color
{
namespace types
{

template<
	typename Access,
	typename Format,
	typename Constness
>
using
pointer
=
typename
mizuiro::color::types::detail::pointer<
	Access,
	Format,
	Constness
>::type;

}
}
}

#endif
