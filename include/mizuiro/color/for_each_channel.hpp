//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FOR_EACH_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_EACH_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/layout.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Color,
	typename Function
>
void
for_each_channel(
	Color const &_color,
	Function const &_function
)
{
	boost::fusion::for_each(
		color::access::layout<
			typename Color::format
		>::execute(
			_color.format_store()
		),
		_function
	);
}

}
}

#endif
