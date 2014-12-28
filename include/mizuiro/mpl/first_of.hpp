//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_FIRST_OF_HPP_INCLUDED
#define MIZUIRO_MPL_FIRST_OF_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List,
	typename Predicate,
	typename Enable = void
>
struct first_of;

template<
	typename List,
	typename Predicate
>
struct first_of<
	List,
	Predicate,
	typename
	std::enable_if<
		Predicate{}(
			typename
			List::head{}
		)
	>::type
>
{
	typedef
	typename
	List::head
	type;
};

template<
	typename List,
	typename Predicate
>
struct first_of<
	List,
	Predicate,
	typename
	std::enable_if<
		!Predicate{}(
			typename
			List::head{}
		)
	>::type
>
{
	typedef
	typename
	mizuiro::mpl::first_of<
		typename List::tail,
		Predicate
	>::type
	type;
};

}
}

#endif
