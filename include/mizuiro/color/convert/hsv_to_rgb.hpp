//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_HSV_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_HSV_TO_RGB_HPP_INCLUDED

#include <mizuiro/color/convert/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/convert/detail/rgb_from_chroma.hpp>
#include <mizuiro/color/convert/same_to_same.hpp> // TODO!
#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/color/is_rgb.hpp>
#include <mizuiro/color/is_hsv.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/normalize.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <cmath>

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
		color::is_hsv
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
	Src const &_source
)
{
	typedef float float_type;

	float_type const
		hue(
			color::normalize<
				float_type
			>(
				_source,
				channel::hue()
			)
		),
		saturation(
			color::normalize<
				float_type
			>(
				_source,
				channel::saturation()
			)
		),
		value(
			color::normalize<
				float_type
			>(
				_source,
				channel::value()
			)
		),
		chroma(
			saturation
			* value
		),
		diff(
			value
			- chroma
		);
	
	float_type const hue_part(
		hue
		*
		static_cast<
			float_type
		>(
			6
		)
	);
	
	typedef int int_type;
		
	float_type const
		largest_part(
			chroma
			*
			static_cast<
				float_type
			>
			(
				static_cast<float_type>(1) -
				std::abs(
					std::fmod(
						hue_part,
						static_cast<float_type>(2)
					)
					- static_cast<float_type>(1)
				)
			));

	typedef color::object<
		Dest
	> dest_type;

	dest_type dest
	(
		color::detail::rgb_from_chroma
		<
			dest_type
		>(
			chroma,
			hue_part,
			largest_part,
			diff
		)
	);

	detail::copy_or_max_alpha
	(
		_source,
		dest
	);
	
	return dest;
}

}
}

#endif
