//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_DETAIL_MPL_HPP_INCLUDED
#define MIZUIRO_RANGE_DETAIL_MPL_HPP_INCLUDED

#include <mizuiro/mpl/empty.hpp>
#include <mizuiro/mpl/head.hpp>
#include <mizuiro/mpl/tail.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace range
{
namespace detail
{

template<
	typename List,
	typename Enable = void
>
struct mpl;

template<
	typename List
>
struct mpl<
	List,
	typename
	std::enable_if<
		mizuiro::mpl::empty<
			List
		>::value
	>::type
>
{
	typedef
	mizuiro::mpl::empty<
		List
	>
	empty;
};

template<
	typename List
>
struct mpl<
	List,
	typename
	std::enable_if<
		!mizuiro::mpl::empty<
			List
		>::value
	>::type
>
{
	typedef
	mizuiro::mpl::empty<
		List
	>
	empty;

	typedef
	mizuiro::mpl::head<
		List
	>
	head_type;

	typedef
	mpl<
		mizuiro::mpl::tail<
			List
		>
	>
	tail_type;

	head_type
	get() const
	{
		return
			head_type{};
	}

	tail_type
	next() const
	{
		return
			tail_type();
	}
};

}
}
}

#endif
