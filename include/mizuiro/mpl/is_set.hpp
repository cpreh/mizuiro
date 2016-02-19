//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_IS_SET_HPP_INCLUDED
#define MIZUIRO_MPL_IS_SET_HPP_INCLUDED

#include <mizuiro/mpl/all_of.hpp>
#include <mizuiro/mpl/detail/count_is_one.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List
>
inline
constexpr
bool
is_set()
{
	return
		mizuiro::mpl::all_of<
			List,
			mizuiro::mpl::detail::count_is_one<
				List
			>
		>();
}

}
}

#endif
