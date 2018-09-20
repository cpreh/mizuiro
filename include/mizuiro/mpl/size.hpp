//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_SIZE_HPP_INCLUDED
#define MIZUIRO_MPL_SIZE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/mpl/empty.hpp>
#include <mizuiro/mpl/tail.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List
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
size()
{
	return
		0u;
}

template<
	typename List
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
size()
{
	return
		mizuiro::mpl::size<
			mizuiro::mpl::tail<
				List
			>
		>()
		+
		1u;
}

}
}

#endif
