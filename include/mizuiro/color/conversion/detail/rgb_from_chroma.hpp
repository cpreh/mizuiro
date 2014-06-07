//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_RGB_FROM_CHROMA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_RGB_FROM_CHROMA_HPP_INCLUDED

#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <exception>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Dest,
	typename FloatType
>
Dest const
rgb_from_chroma(
	FloatType const _chroma,
	FloatType const _hue_part,
	FloatType const _largest_part,
	FloatType const _diff,
	typename Dest::format_store_type const &_format
)
{
	if(
		_hue_part < static_cast<FloatType>(1)
	)
		return
			Dest(
				(color::init::red() %= _chroma + _diff)
				(color::init::green() %= _largest_part + _diff)
				(color::init::blue() %= _diff),
				_format
			);

	if(
		_hue_part < static_cast<FloatType>(2)
	)
		return
			Dest(
				(color::init::red() %= _largest_part + _diff)
				(color::init::green() %= _chroma + _diff)
				(color::init::blue() %= _diff),
				_format
			);

	if(
		_hue_part < static_cast<FloatType>(3)
	)
		return
			Dest(
				(color::init::red() %= _diff)
				(color::init::green() %= _chroma + _diff)
				(color::init::blue() %= _largest_part + _diff),
				_format
			);

	if(
		_hue_part < static_cast<FloatType>(4)
	)
		return
			Dest(
				(color::init::red() %= _diff)
				(color::init::green() %= _largest_part + _diff)
				(color::init::blue() %= _chroma + _diff),
				_format
			);

	if(
		_hue_part < static_cast<FloatType>(5)
	)
		return
			Dest(
				(color::init::red() %= _largest_part + _diff)
				(color::init::green() %= _diff)
				(color::init::blue() %= _chroma + _diff),
				_format
			);

	if(
		_hue_part < static_cast<FloatType>(6)
	)
		return
			Dest(
				(color::init::red() %= _chroma + _diff)
				(color::init::green() %= _diff)
				(color::init::blue() %= _largest_part + _diff),
				_format
			);

	std::terminate();
}

}
}
}
}

#endif
