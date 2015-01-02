//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_LIST_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_MPL_LIST_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/mpl/list_fwd.hpp>
#include <mizuiro/mpl/tag_of_fwd.hpp>
#include <mizuiro/mpl/list_ns/tag.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename... Sequence
>
struct
tag_of<
	mizuiro::mpl::list<
		Sequence...
	>
>
{
	typedef
	mizuiro::mpl::list_ns::tag<
		mizuiro::mpl::list<
			Sequence...
		>
	>
	type;
};

}
}

#endif
