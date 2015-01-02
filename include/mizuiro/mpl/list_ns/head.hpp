//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_LIST_NS_HEAD_HPP_INCLUDED
#define MIZUIRO_MPL_LIST_NS_HEAD_HPP_INCLUDED

#include <mizuiro/mpl/head_ns/tag.hpp>
#include <mizuiro/mpl/list_ns/tag.hpp>


namespace mizuiro
{
namespace mpl
{
namespace head_ns
{

template<
	typename List
>
typename
List::head
head_adl(
	mizuiro::mpl::head_ns::tag,
	mizuiro::mpl::list_ns::tag<
		List
	>
);

}
}
}

#endif
