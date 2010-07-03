//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_NORMALIZE_HPP_INCLUDED
#define MIZUIRO_NORMALIZE_HPP_INCLUDED

#include <mizuiro/color/channel_min.hpp>
#include <mizuiro/color/channel_max.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{

template
<
	typename Float,
	typename ChannelValue
>
typename
boost::enable_if
<
	boost::is_floating_point
	<
		Float
	>,
	Float
>::type
normalize
(
	ChannelValue const &value_
)
{
	return 
		(
			static_cast<Float>
			(
				value_
			)
			-
			static_cast<Float>
			(
				color::channel_min
				<
					ChannelValue
				>()
			)
		)
		/
		(
			static_cast<Float>
			(
				color::channel_max
				<
					ChannelValue
				>()
			)
			-
			static_cast<Float>
			(
				color::channel_min
				<
					ChannelValue
				>()
			)
		);
}

}

#endif
