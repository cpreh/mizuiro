//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_NORMALIZE_HPP_INCLUDED

#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/access/channel_max.hpp>
#include <mizuiro/color/access/channel_min.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Float,
	typename Channel,
	typename Color
>
typename
boost::enable_if<
	boost::mpl::and_<
		mizuiro::color::is_color<
			Color
		>,
		std::is_floating_point<
			Float
		>
	>,
	Float
>::type
normalize(
	Color const &_color,
	Channel const &_channel
)
{
	return
		(
			static_cast<
				Float
			>
			(
				_color.get(
					_channel
				)
			)
			-
			static_cast<
				Float
			>
			(
				mizuiro::color::access::channel_min(
					_color.format_store(),
					_channel
				)
			)
		)
		/
		(
			static_cast<
				Float
			>
			(
				mizuiro::color::access::channel_max(
					_color.format_store(),
					_channel
				)
			)
			-
			static_cast<
				Float
			>
			(
				mizuiro::color::access::channel_min(
					_color.format_store(),
					_channel
				)
			)
		);
}

}
}

#endif
