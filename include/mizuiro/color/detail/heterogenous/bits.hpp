//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_HETEROGENOUS_BITS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HETEROGENOUS_BITS_HPP_INCLUDED

#include <mizuiro/mpl/integral_size.hpp>
#include <mizuiro/mpl/sum.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{
namespace heterogenous
{

template<
	typename Bits
>
using bits
=
mizuiro::mpl::integral_size<
	mizuiro::mpl::sum<
		Bits
	>()
>;

}
}
}
}

#endif
