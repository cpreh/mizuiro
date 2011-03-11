//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_RGB_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_RGB_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/convert/detail/copy_and_convert_channel.hpp>
#include <mizuiro/color/convert/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/is_rgb.hpp>
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
boost::enable_if
<
	boost::mpl::and_
	<
		color::is_rgb
		<
			Dest
		>,
		color::is_rgb
		<
			typename Src::format
		>
	>,
	color::object<
		Dest
	> const
>::type
convert
(
	Src const &_src
)
{
	color::object<
		Dest
	> dest;

	detail::copy_and_convert_channel
	<
		channel::red,
		float
	>
	(
		_src,
		dest
	);

	detail::copy_and_convert_channel
	<
		channel::green,
		float
	>
	(
		_src,
		dest
	);

	detail::copy_and_convert_channel
	<
		channel::blue,
		float
	>
	(
		_src,
		dest
	);

	detail::copy_or_max_alpha
	(
		_src,
		dest
	);

	return dest;
}

}
}

#endif
