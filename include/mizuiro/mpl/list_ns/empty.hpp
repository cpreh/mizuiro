//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_LIST_NS_EMPTY_HPP_INCLUDED
#define MIZUIRO_MPL_LIST_NS_EMPTY_HPP_INCLUDED

#include <mizuiro/mpl/empty_ns/tag.hpp>
#include <mizuiro/mpl/list_ns/tag.hpp>


namespace mizuiro
{
namespace mpl
{
namespace empty_ns
{

template<
	typename List
>
typename
List::empty
empty_adl(
	mizuiro::mpl::empty_ns::tag,
	mizuiro::mpl::list_ns::tag<
		List
	>
);

}
}
}

#endif
