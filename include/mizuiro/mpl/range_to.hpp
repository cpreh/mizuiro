//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_RANGE_TO_HPP_INCLUDED
#define MIZUIRO_MPL_RANGE_TO_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/mpl/false.hpp>
#include <mizuiro/mpl/head.hpp>
#include <mizuiro/mpl/range_to_fwd.hpp>
#include <mizuiro/mpl/tail.hpp>
#include <mizuiro/mpl/true.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List
>
struct range_to<
	List,
	0u
>
{
	typedef
	mizuiro::mpl::true_
	empty;
};

template<
	typename List,
	mizuiro::size_type Index
>
struct range_to
{
	typedef
	mizuiro::mpl::false_
	empty;

	typedef
	mizuiro::mpl::head<
		List
	>
	head;

	typedef
	mizuiro::mpl::range_to<
		mizuiro::mpl::tail<
			List
		>,
		Index
		-
		1u
	>
	tail;
};

}
}

#endif
