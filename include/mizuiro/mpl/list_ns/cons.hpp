//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_LIST_NS_CONS_HPP_INCLUDED
#define MIZUIRO_MPL_LIST_NS_CONS_HPP_INCLUDED

#include <mizuiro/mpl/cons_list.hpp>
#include <mizuiro/mpl/cons_ns/tag.hpp>
#include <mizuiro/mpl/list_ns/tag.hpp>


namespace mizuiro
{
namespace mpl
{
namespace cons_ns
{

template<
	typename Head,
	typename Tail
>
mizuiro::mpl::cons_list<
	Head,
	Tail
>
cons_adl(
	mizuiro::mpl::cons_ns::tag,
	mizuiro::mpl::list_ns::tag<
		Tail
	>,
	Head const &
);

}
}
}

#endif
