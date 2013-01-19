//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_ALPHA_HPP_INCLUDED

#include <mizuiro/color/layout/alpha.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/is_same.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template
<
	typename Format
>
struct is_alpha
:
boost::is_same<
	typename Format::layout,
	layout::alpha
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
