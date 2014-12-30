//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_SIZE_LIST_HPP_INCLUDED
#define MIZUIRO_MPL_SIZE_LIST_HPP_INCLUDED

#include <mizuiro/mpl/integral_size.hpp>
#include <mizuiro/mpl/list.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	mizuiro::size_type... Elements
>
using
size_list
=
mizuiro::mpl::list<
	mizuiro::mpl::integral_size<
		Elements
	>...
>;

}
}

#endif