//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_DETAIL_RGB_FROM_CHROMA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_DETAIL_RGB_FROM_CHROMA_HPP_INCLUDED

#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <stdexcept>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Dest,
	typename FloatType,
	typename PartType
>
Dest const
rgb_from_chroma(
	FloatType const chroma,
	PartType const hue_part,
	FloatType const largest_part
)
{
	switch(hue_part)
	{
	case 0:
		return
			Dest(
				color::init::red %= chroma,
				color::init::green %= largest_part,
				color::init::blue %= 0.
			);
	case 1:
		return
			Dest(
				color::init::red %= largest_part,
				color::init::green %= chroma,
				color::init::blue %= 0.
			);
	case 2:
		return
			Dest(
				color::init::red %= 0.,
				color::init::green %= chroma,
				color::init::blue %= largest_part
			);
	case 3:
		return
			Dest(
				color::init::red %= 0.,
				color::init::green %= largest_part,
				color::init::blue %= chroma
			);
	case 4:
		return
			Dest(
				color::init::red %= largest_part,
				color::init::green %= 0.,
				color::init::blue %= chroma
			);
	case 5:
		return
			Dest(
				color::init::red %= chroma,
				color::init::green %= 0.,
				color::init::blue %= largest_part
			);
	}

	// TODO: add our own exception type!
	throw std::logic_error(
		"rgb_from_chroma: Invalid hue!"	
	);
}

}
}
}

#endif
