//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_HOMOGENOUS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_HOMOGENOUS_STATIC_HPP_INCLUDED

#include <mizuiro/color/homogenous_static_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Format
>
struct is_homogenous_static
:
boost::false_type
{};

template<
	typename ChannelType,
	typename Layout
>
struct is_homogenous_static<
	color::homogenous_static<
		ChannelType,
		Layout
	>
>
:
boost::true_type
{};

}
}

#endif
