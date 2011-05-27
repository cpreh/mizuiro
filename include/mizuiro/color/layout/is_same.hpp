//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_LAYOUT_IS_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_IS_SAME_HPP_INCLUDED

#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{
namespace layout
{

template<
	typename A,
	typename B
>
struct is_same
:
boost::is_same<
	A,
	B
>
{
};

template<
	template<
		typename
	> class Outer,
	typename Inner1,
	typename Inner2
>
struct is_same<
	Outer<
		Inner1
	>,
	Outer<
		Inner2
	>
>
:
boost::true_type
{
};

}
}
}

#endif
