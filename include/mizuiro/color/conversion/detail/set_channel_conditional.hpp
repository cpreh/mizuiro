//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_SET_CHANNEL_CONDITIONAL_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_SET_CHANNEL_CONDITIONAL_HPP_INCLUDED

#include <mizuiro/color/access/has_channel.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/has_channel_static.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Channel,
	typename Color
>
typename boost::enable_if<
	mizuiro::color::types::has_channel_static<
		typename Color::format,
		Channel
	>,
	void
>::type
set_channel_conditional(
	Color &_color,
	typename mizuiro::color::types::channel_value<
		typename Color::format,
		Channel
	>::type const &_value
)
{
	if(
		mizuiro::color::access::has_channel<
			typename Color::format,
			Channel
		>::execute(
			_color.format_store()
		)
	)
		_color.set(
			Channel(),
			_value
		);
}

template<
	typename Channel,
	typename Color
>
typename boost::disable_if<
	mizuiro::color::types::has_channel_static<
		typename Color::format,
		Channel
	>,
	void
>::type
set_channel_conditional(
	Color &,
	typename mizuiro::color::types::channel_value<
		typename Color::format,
		Channel
	>::type const &
)
{
}

}
}
}
}

#endif
