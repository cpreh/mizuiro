//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/make_range.hpp>
#include <mizuiro/range/for_each.hpp>


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
	mizuiro::range::for_each(
		mizuiro::color::make_range(
			_color
		),
		[
			&_function,
			&_filter
		](
			auto const &_value
		)
		{
			if(
				_filter(
					_value
				)
			)
				_function(
					_value
				);
		}
	);
}

}
}

#endif
