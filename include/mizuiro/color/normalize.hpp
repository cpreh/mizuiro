//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/normalize.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Float,
	typename Channel,
	typename Color
>
typename
boost::enable_if
<
	boost::mpl::and_
	<
		mizuiro::color::is_color
		<
			Color
		>,
		boost::is_floating_point
		<
			Float
		>
	>,
	Float
>::type
normalize
(
	Color const &_color,
	Channel const &_channel
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
			_color.get(
				_channel
			)
		);
}

}
}

#endif
