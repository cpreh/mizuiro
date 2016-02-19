//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED
#define MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED

#include <mizuiro/detail/bit_count_at_least.hpp>
#include <mizuiro/mpl/first_of.hpp>
#include <mizuiro/mpl/list.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Bits
>
using uint_least
=
typename
mizuiro::mpl::first_of<
	mizuiro::mpl::list<
		unsigned char,
		unsigned short,
		unsigned int,
		unsigned long,
		unsigned long long
	>,
	mizuiro::detail::bit_count_at_least<
		Bits
	>
>::type;

}
}

#endif
