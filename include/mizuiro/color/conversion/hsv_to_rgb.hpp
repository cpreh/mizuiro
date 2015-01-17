//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_HSV_TO_RGB_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_HSV_TO_RGB_HPP_INCLUDED

#include <mizuiro/no_init.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/channel/hue.hpp>
#include <mizuiro/color/channel/saturation.hpp>
#include <mizuiro/color/channel/value.hpp>
#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/conversion/detail/rgb_from_chroma.hpp>
#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cmath>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{

template<
	typename Dest,
	typename Src
>
mizuiro::color::object<
	Dest
> const
hsv_to_rgb(
	Src const &_source,
	typename
	mizuiro::color::object<
		Dest
	>::format_store_type const &_format
		= mizuiro::color::format::argument<
			Dest
		>::get()
)
{
	typedef float float_type;

	float_type const
		hue(
			mizuiro::color::normalize<
				float_type
			>(
				_source,
				mizuiro::color::channel::hue()
			)
		),
		saturation(
			mizuiro::color::normalize<
				float_type
			>(
				_source,
				mizuiro::color::channel::saturation()
			)
		),
		value(
			mizuiro::color::normalize<
				float_type
			>(
				_source,
				mizuiro::color::channel::value()
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

	typedef
	mizuiro::color::object<
		Dest
	>
	dest_type;

	dest_type dest{
		mizuiro::no_init{},
		_format
	};

	mizuiro::color::conversion::detail::rgb_from_chroma(
		dest,
		chroma,
		hue_part,
		largest_part,
		diff
	);

	mizuiro::color::conversion::detail::copy_or_max_alpha(
		_source,
		dest
	);

	return
		dest;
}

}
}
}

#endif
