//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_INDEX_OF_HPP_INCLUDED
#define MIZUIRO_MPL_INDEX_OF_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/mpl/detail/index_of.hpp>


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
mizuiro::size_type
index_of()
{
	return
		mizuiro::mpl::detail::index_of<
			List,
			Element
		>::type::value;
}

}
}

#endif
