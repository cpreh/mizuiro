//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_SIZE_HPP_INCLUDED
#define MIZUIRO_MPL_SIZE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


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
	List::empty::value,
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
	!List::empty::value,
	mizuiro::size_type
>::type
size()
{
	return
		mizuiro::mpl::size<
			typename
			List::tail
		>()
		+
		1u;
}

}
}

#endif
