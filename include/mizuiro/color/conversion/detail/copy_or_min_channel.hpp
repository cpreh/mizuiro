//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_MIN_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_MIN_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/conversion/detail/channel_to_min_function.hpp>
#include <mizuiro/color/conversion/detail/copy_or_default_channel.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Converter,
	typename Channel,
	typename Src,
	typename Dest
>
inline
void
copy_or_min_channel(
	Converter const &_converter,
	Channel const &_channel,
	Src const &_src,
	Dest &_dest
)
{
	mizuiro::color::conversion::detail::copy_or_default_channel(
		_converter,
		mizuiro::color::conversion::detail::channel_to_min_function<
			Dest
		>(
			_dest
		),
		_channel,
		_src,
		_dest
	);
}

}
}
}
}

#endif
