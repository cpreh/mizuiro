//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/get_channel.hpp>
#include <mizuiro/color/make_range.hpp>
#include <fcppt/algorithm/loop.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Function,
	typename DynamicFilter
>
inline
void
for_some_channels(
	Color const  &_color,
	Function const &_function,
	DynamicFilter const &_filter
)
{
	fcppt::algorithm::loop(
		mizuiro::color::make_range(
			_color
		),
		[
			&_function,
			&_filter
		](
			auto const _channel
		)
		{
			if(
				_filter(
					mizuiro::color::get_channel(
						_channel
					)
				)
			)
			{
				_function(
					mizuiro::color::get_channel(
						_channel
					)
				);
			}
		}
	);
}

}
}

#endif
