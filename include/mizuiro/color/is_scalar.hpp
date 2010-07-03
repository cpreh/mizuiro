//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_SCALAR_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_SCALAR_HPP_INCLUDED

#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/int.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Format
>
struct is_scalar
:
boost::mpl::equal_to<
	boost::mpl::size<
		typename Format::layout::order
	>,
	boost::mpl::int_<
		1
	>
>
{};

}
}

#endif
