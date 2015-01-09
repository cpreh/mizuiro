//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_TRANSFORM_HPP_INCLUDED
#define MIZUIRO_MPL_TRANSFORM_HPP_INCLUDED

#include <mizuiro/mpl/detail/transform.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List,
	typename Function
>
using
transform
=
typename
mizuiro::mpl::detail::transform<
	List,
	Function
>::type;

}
}

#endif
