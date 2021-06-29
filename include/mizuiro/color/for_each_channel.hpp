//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FOR_EACH_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_EACH_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/get_channel.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/make_range.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_mpl.hpp>


// TODO(philipp): Where should be put this? ^


namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Function
>
inline
void
for_each_channel(
	Color const &_color,
	Function const &_function
)
{
	static_assert(
		mizuiro::color::is_color<
			Color
		>::value,
		"Color must be a color type"
	);

	fcppt::algorithm::loop(
		mizuiro::color::make_range(
			_color
		),
		[
			&_function
		](
			auto const _channel
		)
		{
			return
				_function(
					mizuiro::color::get_channel(
						_channel
					)
				);
		}
	);
}

}
}

#endif
