//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_RGB_TO_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_RGB_TO_GRAY_HPP_INCLUDED

#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/gray.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/luminance.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/is_gray.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{
template
<
	typename Dest,
	typename Src
>
typename
boost::enable_if_c
<
	is_gray<Dest>::value && 
	is_rgb<typename Src::format>::value &&
	!has_channel<typename Src::format,channel::alpha>::value,
	object<Dest> const
>::type
convert(
	Src const &src)
{
	typedef 
	object<Dest> 
	dest_type;
	
	dest_type dest;
	
	dest.template set<channel::gray>(
		denormalize
		<
			typename dest_type::format,
			channel::gray,
			float
		>(
			luminance(
				normalize<channel::red,float>(
					src),
				normalize<channel::green,float>(
					src),
				normalize<channel::blue,float>(
					src))));

	return dest;
}

template
<
	typename Dest,
	typename Src
>
typename
boost::enable_if_c
<
	is_gray<Dest>::value && 
	is_rgb<typename Src::format>::value && 
	has_channel<typename Src::format,channel::alpha>::value,
	object<Dest> const
>::type
convert(
	Src const &src)
{
	typedef 
	object<Dest> 
	dest_type;
	
	dest_type dest;
	
	dest.template set<channel::gray>(
		denormalize
		<
			typename dest_type::format,
			channel::gray,
			float
		>(
			luminance(
				normalize<channel::red,float>(
					src),
				normalize<channel::green,float>(
					src),
				normalize<channel::blue,float>(
					src)) * 
			normalize<channel::alpha,float>(
				src)));

	return dest;
}
}
}

#endif
