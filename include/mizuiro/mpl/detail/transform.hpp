//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_DETAIL_TRANSFORM_HPP_INCLUDED
#define MIZUIRO_MPL_DETAIL_TRANSFORM_HPP_INCLUDED

#include <mizuiro/mpl/apply.hpp>
#include <mizuiro/mpl/cons.hpp>
#include <mizuiro/mpl/empty.hpp>
#include <mizuiro/mpl/head.hpp>
#include <mizuiro/mpl/list.hpp>
#include <mizuiro/mpl/tail.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace mpl
{
namespace detail
{

template<
	typename List,
	typename Function,
	typename Enable = void
>
struct transform;

template<
	typename List,
	typename Function
>
struct transform<
	List,
	Function,
	typename
	std::enable_if<
		mizuiro::mpl::empty<
			List
		>::value
	>::type
>
{
	typedef
	mizuiro::mpl::list<>
	type;
};

template<
	typename List,
	typename Function
>
struct transform<
	List,
	Function,
	typename
	std::enable_if<
		!mizuiro::mpl::empty<
			List
		>::value
	>::type
>
{
	typedef
	mizuiro::mpl::cons<
		decltype(
			mizuiro::mpl::apply<
				Function,
				mizuiro::mpl::head<
					List
				>
			>()
		),
		typename
		mizuiro::mpl::detail::transform<
			mizuiro::mpl::tail<
				List
			>,
			Function
		>::type
	>
	type;
};

}
}
}

#endif
