//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_CONTAINS_HPP_INCLUDED
#define MIZUIRO_MPL_CONTAINS_HPP_INCLUDED

#include <mizuiro/mpl/empty.hpp>
#include <mizuiro/mpl/head.hpp>
#include <mizuiro/mpl/tail.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List,
	typename Element
>
inline
constexpr
typename
std::enable_if<
	mizuiro::mpl::empty<
		List
	>::value,
	bool
>::type
contains()
{
	return
		false;
}

template<
	typename List,
	typename Element
>
inline
constexpr
typename
std::enable_if<
	!mizuiro::mpl::empty<
		List
	>::value,
	bool
>::type
contains()
{
	return
		std::is_same<
			mizuiro::mpl::head<
				List
			>,
			Element
		>::value
		||
		mizuiro::mpl::contains<
			mizuiro::mpl::tail<
				List
			>,
			Element
		>();
}

}
}

#endif
