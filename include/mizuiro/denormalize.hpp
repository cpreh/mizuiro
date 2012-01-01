//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_DENORMALIZE_HPP_INCLUDED

#include <mizuiro/color/channel_max.hpp>
#include <mizuiro/color/channel_min.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{

/// Denormalizes a float value
/**
 * @param src is supposed to be in [0,1].
 * @return 0 maps to channel_min<Dest>(), 1 maps to channel_max<Dest>()
*/
template
<
	typename Dest,
	typename Float
>
typename boost::enable_if
<
	boost::is_floating_point
	<
		Float
	>,
	Dest
>::type
denormalize
(
	Float const src
)
{
	return
		static_cast<Dest>
		(
			static_cast<Float>
			(
				color::channel_min
				<
					Dest
				>()
			)
			+
			src
			*
			(
				static_cast<Float>
				(
					color::channel_max
					<
						Dest
					>()
				)
				-
				static_cast<Float>
				(
					color::channel_min
					<
						Dest
					>()
				)
			)
		);
}

}

#endif
