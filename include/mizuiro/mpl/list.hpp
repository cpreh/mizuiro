//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_LIST_HPP_INCLUDED
#define MIZUIRO_MPL_LIST_HPP_INCLUDED

#include <mizuiro/mpl/false.hpp>
#include <mizuiro/mpl/list_fwd.hpp>
#include <mizuiro/mpl/true.hpp>


namespace mizuiro
{
namespace mpl
{

template<>
struct list<>
{
	typedef
	mizuiro::mpl::true_
	empty;
};

template<
	typename Head,
	typename... Tail
>
struct list<
	Head,
	Tail...
>
{
	typedef
	mizuiro::mpl::false_
	empty;

	typedef
	Head
	head;

	typedef
	mizuiro::mpl::list<
		Tail...
	>
	tail;
};

}
}

#endif
