//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_CONTAINS_IF_HPP_INCLUDED
#define MIZUIRO_MPL_CONTAINS_IF_HPP_INCLUDED

#include <mizuiro/mpl/apply.hpp>
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
	typename Predicate
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
contains_if()
{
	return
		false;
}

template<
	typename List,
	typename Predicate
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
contains_if()
{
	return
		mizuiro::mpl::apply<
			Predicate,
			mizuiro::mpl::head<
				List
			>
		>()
		||
		mizuiro::mpl::contains_if<
			mizuiro::mpl::tail<
				List
			>,
			Predicate
		>();
}

}
}

#endif
