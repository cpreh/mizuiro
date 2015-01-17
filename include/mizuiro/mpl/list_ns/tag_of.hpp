//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_LIST_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_MPL_LIST_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/mpl/cons_list_fwd.hpp>
#include <mizuiro/mpl/list_fwd.hpp>
#include <mizuiro/mpl/range_to_fwd.hpp>
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

template<
	typename Head,
	typename Tail
>
struct
tag_of<
	mizuiro::mpl::cons_list<
		Head,
		Tail
	>
>
{
	typedef
	mizuiro::mpl::list_ns::tag<
		mizuiro::mpl::cons_list<
			Head,
			Tail
		>
	>
	type;

};

template<
	typename List,
	mizuiro::size_type Index
>
struct
tag_of<
	mizuiro::mpl::range_to<
		List,
		Index
	>
>
{
	typedef
	mizuiro::mpl::list_ns::tag<
		mizuiro::mpl::range_to<
			List,
			Index
		>
	>
	type;

};

}
}

#endif
