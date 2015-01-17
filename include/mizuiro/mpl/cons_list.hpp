//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_CONS_LIST_HPP_INCLUDED
#define MIZUIRO_MPL_CONS_LIST_HPP_INCLUDED

#include <mizuiro/mpl/cons_list_fwd.hpp>
#include <mizuiro/mpl/false.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename Head,
	typename Tail
>
struct cons_list
{
	typedef
	mizuiro::mpl::false_
	empty;

	typedef
	Head
	head;

	typedef
	Tail
	tail;
};

}
}

#endif
