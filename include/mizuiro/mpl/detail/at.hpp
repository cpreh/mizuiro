//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_DETAIL_AT_HPP_INCLUDED
#define MIZUIRO_MPL_DETAIL_AT_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/mpl/head.hpp>
#include <mizuiro/mpl/tail.hpp>


namespace mizuiro
{
namespace mpl
{
namespace detail
{

template<
	typename List,
	mizuiro::size_type Index
>
struct at;

template<
	typename List
>
struct at<
	List,
	0u
>
{
	typedef
	mizuiro::mpl::head<
		List
	>
	type;
};

template<
	typename List,
	mizuiro::size_type Index
>
struct at
{
	typedef
	typename
	mizuiro::mpl::detail::at<
		mizuiro::mpl::tail<
			List
		>,
		Index - 1u
	>::type
	type;
};

}
}
}

#endif
