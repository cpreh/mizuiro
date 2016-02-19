//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_POINTER_HPP_INCLUDED
#define MIZUIRO_ACCESS_POINTER_HPP_INCLUDED

#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/access/raw_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace access
{

template<
	typename Access,
	typename Normal
>
using
pointer
=
typename
std::conditional<
	std::is_same<
		Access,
		mizuiro::access::raw
	>::value,
	mizuiro::raw_pointer,
	Normal
>::type;

}
}

#endif
