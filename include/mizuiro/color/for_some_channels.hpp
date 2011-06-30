//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/access/layout.hpp>
#include <mizuiro/color/detail/for_some_channels_functor.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Function,
	typename Filter
>
void
for_some_channels(
	Color const  &_color,
	Function const &_function,
	Filter const &_filter
)
{
	boost::fusion::for_each(
		color::access::layout<
			typename Color::format
		>::execute(
			_color.format_store()
		),
		detail::for_some_channels_functor<
			Function,
			Filter
		>(
			_function,
			_filter
		)
	);
}

}
}

#endif
