//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_INTEGRAL_SIZE_HPP_INCLUDED
#define MIZUIRO_INTEGRAL_SIZE_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{

/**
\brief An integral constant size of mizuiro::size_type

TODO: Use std::integral_constant here?

\tparam Size The constant size
*/
template<
	mizuiro::size_type Size
>
using integral_size
=
boost::mpl::integral_c<
	mizuiro::size_type,
	Size
>;

}

#endif
