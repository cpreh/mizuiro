//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_GRAY_HPP_INCLUDED

#include <mizuiro/color/layout/gray.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Format
>
struct is_gray
:
boost::is_same<
	typename Format::layout,
	layout::gray
>
{
};

}
}

#endif
