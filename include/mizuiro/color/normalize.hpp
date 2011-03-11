//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED

#include <mizuiro/normalize.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_floating_point.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Channel,
	typename Float,
	typename Color
>
typename
boost::enable_if
<
	boost::is_floating_point
	<
		Float
	>,
	Float
>::type
normalize
(
	Color const &_color
)
{
	return 
		::mizuiro::normalize<
			Float,
			typename color::types::channel_value
			<
				typename Color::format,
				Channel
			>::type
		>(
			_color.template get
			<
				Channel
			>()
		);
}

}
}

#endif
