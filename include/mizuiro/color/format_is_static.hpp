//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_IS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_IS_STATIC_HPP_INCLUDED

#include <mizuiro/color/homogenous_static_fwd.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Format
>
struct format_is_static
:
boost::false_type
{
};

template<
	typename ChannelType,
	typename Layout
>
struct format_is_static<
	color::homogenous_static<
		ChannelType,
		Layout
	>
>
:
boost::true_type
{
};

}
}

#endif