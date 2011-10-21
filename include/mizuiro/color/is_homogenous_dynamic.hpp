//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_HOMOGENOUS_DYNAMIC_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_HOMOGENOUS_DYNAMIC_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/color/homogenous_dynamic_fwd.hpp>
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
struct is_homogenous_dynamic
:
boost::false_type
{};

template<
	typename ChannelType,
	typename AvailableChannels,
	AvailableChannels AllChannels,
	mizuiro::size_type Size
>
struct is_homogenous_dynamic<
	color::homogenous_dynamic<
		ChannelType,
		AvailableChannels,
		AllChannels,
		Size
	>
>
:
boost::true_type
{};

}
}

#endif
