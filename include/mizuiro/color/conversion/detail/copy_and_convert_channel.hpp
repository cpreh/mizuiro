//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_AND_CONVERT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_AND_CONVERT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/normalize.hpp>


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
	typename Src,
	typename Dest
>
void
copy_and_convert_channel(
	Channel const &_channel,
	Src const &_src,
	Dest &_dest
)
{
	// TODO: Create a better version of this
	typedef
	float
	float_type;

	_dest.set(
		_channel,
		mizuiro::color::denormalize<
			typename Dest::format
		>(
			_dest.format_store(),
			_channel,
			mizuiro::color::normalize<
				float_type
			>(
				_src,
				_channel
			)
		)
	);
}

}
}
}
}

#endif
