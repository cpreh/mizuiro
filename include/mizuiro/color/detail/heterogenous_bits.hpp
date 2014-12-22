//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_HETEROGENOUS_BITS_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_HETEROGENOUS_BITS_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/accumulate.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/plus.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Bits
>
using heterogenous_bits
=
boost::mpl::accumulate<
	Bits,
	typename mizuiro::integral_size<
		0u
	>::type,
	boost::mpl::plus<
		boost::mpl::_1,
		boost::mpl::_2
	>
>;

}
}
}

#endif
