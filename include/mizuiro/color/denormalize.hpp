//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED
#define MIZUIRO_COLOR_DENORMALIZE_HPP_INCLUDED

#include <mizuiro/color/channel_max.hpp>
#include <mizuiro/color/channel_min.hpp>
#include <mizuiro/color/format_store_fwd.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

template
<
	typename Format,
	typename Channel,
	typename Float
>
typename boost::enable_if
<
	boost::is_floating_point
	<
		Float
	>,
	typename
	mizuiro::color::types::channel_value
	<
		Format,
		Channel
	>::type
>::type
denormalize
(
	mizuiro::color::format_store<
		Format
	> const &_format_store,
	Channel const &_channel,
	Float const _src
)
{
	return
		static_cast<
			typename
			mizuiro::color::types::channel_value
			<
				Format,
				Channel
			>::type
		>
		(
			static_cast<
				Float
			>
			(
				mizuiro::color::channel_min(
					_format_store,
					_channel
				)
			)
			+
			_src
			*
			(
				static_cast<
					Float
				>
				(
					mizuiro::color::channel_max(
						_format_store,
						_channel
					)
				)
				-
				static_cast<
					Float
				>
				(
					mizuiro::color::channel_min(
						_format_store,
						_channel
					)
				)
			)
		);
}

}
}

#endif
