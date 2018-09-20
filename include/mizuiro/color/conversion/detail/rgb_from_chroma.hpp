//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_RGB_FROM_CHROMA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_RGB_FROM_CHROMA_HPP_INCLUDED

#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>
#include <mizuiro/color/conversion/detail/set_chroma_parts.hpp>
#include <fcppt/config/external_begin.hpp>
#include <exception>
#include <fcppt/config/external_end.hpp>


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
void
rgb_from_chroma(
	Dest &_dest,
	FloatType const _chroma,
	FloatType const _hue_part,
	FloatType const _largest_part,
	FloatType const _diff
)
{
	mizuiro::color::conversion::detail::set_chroma_parts<
		Dest,
		FloatType
	>  const set_parts{
		_dest,
		_chroma
		+
		_diff,
		_largest_part
		+
		_diff,
		_diff
	};

	switch(
		static_cast<
			int
		>(
			_hue_part
		)
	)
	{
	case 0:
		return
			set_parts(
				mizuiro::color::channel::red(),
				mizuiro::color::channel::green(),
				mizuiro::color::channel::blue()
			);
	case 1:
		return
			set_parts(
				mizuiro::color::channel::green(),
				mizuiro::color::channel::red(),
				mizuiro::color::channel::blue()
			);
	case 2:
		return
			set_parts(
				mizuiro::color::channel::green(),
				mizuiro::color::channel::blue(),
				mizuiro::color::channel::red()
			);
	case 3:
		return
			set_parts(
				mizuiro::color::channel::blue(),
				mizuiro::color::channel::green(),
				mizuiro::color::channel::red()
			);
	case 4:
		return
			set_parts(
				mizuiro::color::channel::blue(),
				mizuiro::color::channel::red(),
				mizuiro::color::channel::green()
			);
	case 5:
		return
			set_parts(
				mizuiro::color::channel::red(),
				mizuiro::color::channel::blue(),
				mizuiro::color::channel::green()
			);
	}

	std::terminate();
}

}
}
}
}

#endif
