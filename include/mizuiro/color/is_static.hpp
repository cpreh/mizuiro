//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_STATIC_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_STATIC_HPP_INCLUDED

#include <mizuiro/color/heterogenous_static_fwd.hpp>
#include <mizuiro/color/homogenous_static_fwd.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct is_static
:
boost::false_type
{
};

template<
	typename ChannelType,
	typename Layout
>
struct is_static<
	mizuiro::color::homogenous_static<
		ChannelType,
		Layout
	>
>
:
boost::true_type
{
};

template<
	typename ChannelBits,
	typename Layout
>
struct is_static<
	mizuiro::color::heterogenous_static<
		ChannelBits,
		Layout
	>
>
:
boost::true_type
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
