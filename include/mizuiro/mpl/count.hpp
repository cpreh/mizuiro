//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_COUNT_HPP_INCLUDED
#define MIZUIRO_MPL_COUNT_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/mpl/empty.hpp>
#include <mizuiro/mpl/head.hpp>
#include <mizuiro/mpl/tail.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List,
	typename Element
>
inline
constexpr
typename
std::enable_if<
	mizuiro::mpl::empty<
		List
	>::value,
	mizuiro::size_type
>::type
count()
{
	return
		0u;
}

template<
	typename List,
	typename Element
>
inline
constexpr
typename
std::enable_if<
	!mizuiro::mpl::empty<
		List
	>::value,
	mizuiro::size_type
>::type
count()
{
	return
		mizuiro::mpl::count<
			mizuiro::mpl::tail<
				List
			>,
			Element
		>()
		+
		(
			std::is_same<
				mizuiro::mpl::head<
					List
				>,
				Element
			>::value
			?
				1u
			:
				0u
		);
}

}
}

#endif
