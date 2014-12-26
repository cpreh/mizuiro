//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_DETAIL_MPL_HPP_INCLUDED
#define MIZUIRO_RANGE_DETAIL_MPL_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace range
{
namespace detail
{

// TODO: This is ugly
template<
	typename  List,
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
		List::empty::value
	>::type
>
{
	typedef
	typename
	List::empty
	empty;
};

template<
	typename List
>
struct mpl<
	List,
	typename
	std::enable_if<
		!List::empty::value
	>::type
>
{
	typedef
	typename
	List::empty
	empty;

	typename
	List::head
	get() const
	{
		return
			typename
			List::head{};
	}

	mpl<
		typename
		List::tail
	>
	next() const
	{
		return
			mpl<
				typename
				List::tail
			>();
	}
};

}
}
}

#endif
