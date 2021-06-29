//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_RANGE_TO_HPP_INCLUDED
#define MIZUIRO_DETAIL_RANGE_TO_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <mizuiro/size_type.hpp>
#include <fcppt/mpl/list/take.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename List,
	mizuiro::size_type Size
>
using
range_to
=
fcppt::mpl::list::take<
	List,
	mizuiro::integral_size<
		Size
	>
>;

}
}

#endif
