//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_CONVERT_CHANNEL_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_CONVERT_CHANNEL_FUNCTION_HPP_INCLUDED

#include <mizuiro/color/conversion/detail/convert_channel.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

struct convert_channel_function
{
	template<
		typename Channel,
		typename Src,
		typename Dest
	>
	void
	operator()(
		Channel const &_channel,
		Src const &_src,
		Dest &_dest
	) const
	{
		mizuiro::color::conversion::detail::convert_channel(
			_channel,
			_src,
			_dest
		);
	}
};

}
}
}
}

#endif
