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
	typename FloatType
>
Dest const
rgb_from_chroma(
	FloatType const chroma,
	FloatType const hue_part,
	FloatType const largest_part,
	FloatType const diff
)
{
	if (hue_part < static_cast<FloatType>(1))
		return
			Dest(
				(color::init::red %= chroma + diff)
				(color::init::green %= largest_part + diff)
				(color::init::blue %= diff)
			);
	if (hue_part < static_cast<FloatType>(2))
		return
			Dest(
				(color::init::red %= largest_part + diff)
				(color::init::green %= chroma + diff)
				(color::init::blue %= diff)
			);
	if (hue_part < static_cast<FloatType>(3))
		return
			Dest(
				(color::init::red %= diff)
				(color::init::green %= chroma + diff)
				(color::init::blue %= largest_part + diff)
			);
	if (hue_part < static_cast<FloatType>(4))
		return
			Dest(
				(color::init::red %= diff)
				(color::init::green %= largest_part + diff)
				(color::init::blue %= chroma + diff)
			);
	if (hue_part < static_cast<FloatType>(5))
		return
			Dest(
				(color::init::red %= largest_part + diff)
				(color::init::green %= diff)
				(color::init::blue %= chroma + diff)
			);
	if (hue_part < static_cast<FloatType>(6))
		return
			Dest(
				(color::init::red %= chroma + diff)
				(color::init::green %= diff)
				(color::init::blue %= largest_part + diff)
			);

	// TODO: add our own exception type!
	throw std::logic_error(
		"rgb_from_chroma: Invalid hue!"	
	);
}

}
}
}

#endif
