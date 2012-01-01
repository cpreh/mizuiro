//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_TYPES_HOMOGENOUS_DYNAMIC_HPP_INCLUDED
#define MIZUIRO_COLOR_TYPES_HOMOGENOUS_DYNAMIC_HPP_INCLUDED

#include <mizuiro/color/is_homogenous_dynamic.hpp>
#include <mizuiro/color/types/has_channel_static.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{
namespace types
{

template
<
	typename Format,
	typename Channel
>
struct has_channel_static<
	Format,
	Channel,
	typename boost::enable_if<
		mizuiro::color::is_homogenous_dynamic<
			Format
		>
	>::type
>
:
boost::mpl::true_
{
};

}
}
}

#endif
