//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_DETAIL_COUNT_IS_ONE_HPP_INCLUDED
#define MIZUIRO_MPL_DETAIL_COUNT_IS_ONE_HPP_INCLUDED

#include <mizuiro/mpl/count.hpp>


namespace mizuiro
{
namespace mpl
{
namespace detail
{

template<
	typename List
>
struct count_is_one
{
	template<
		typename Element
	>
	static
	constexpr
	bool
	apply()
	{
		return
			mizuiro::mpl::count<
				List,
				Element
			>()
			==
			1u;
	}
};

}
}
}

#endif
