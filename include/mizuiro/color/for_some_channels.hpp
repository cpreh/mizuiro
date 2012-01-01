//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED
#define MIZUIRO_COLOR_FOR_SOME_CHANNELS_HPP_INCLUDED

#include <mizuiro/color/access/layout.hpp>
#include <mizuiro/color/detail/for_some_channels_functor.hpp>
#include <mizuiro/detail/make_filter_view.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/fusion/algorithm/iteration/for_each.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename StaticFilter,
	typename Color,
	typename Function,
	typename DynamicFilter
>
void
for_some_channels(
	Color const  &_color,
	Function const &_function,
	DynamicFilter const &_filter
)
{
	boost::fusion::for_each(
		mizuiro::detail::make_filter_view<
			StaticFilter
		>(
			color::access::layout<
				typename Color::format
			>::execute(
				_color.format_store()
			)
		),
		detail::for_some_channels_functor<
			Function,
			DynamicFilter
		>(
			_function,
			_filter
		)
	);
}

}
}

#endif
