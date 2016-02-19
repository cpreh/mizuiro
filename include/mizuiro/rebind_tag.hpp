//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_REBIND_TAG_HPP_INCLUDED
#define MIZUIRO_REBIND_TAG_HPP_INCLUDED

#include <mizuiro/detail/rebind_tag.hpp>


namespace mizuiro
{

template<
	typename Tag,
	typename NewInner
>
using
rebind_tag
=
typename
mizuiro::detail::rebind_tag<
	Tag,
	NewInner
>::type;

}

#endif
