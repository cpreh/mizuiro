//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/is_homogenous_dynamic.hpp>
#include <mizuiro/color/is_homogenous_static.hpp>
#include <boost/mpl/or.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Format
>
struct is_homogenous
:
boost::mpl::or_<
	color::is_homogenous_static<
		Format
	>,
	color::is_homogenous_dynamic<
		Format
	>
>
{
};

}
}

#endif
