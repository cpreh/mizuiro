//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_COPY_OR_MAX_ALPHA_HPP_INCLUDED

#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/conversion/detail/channel_to_max_function.hpp>
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
	typename Src,
	typename Dest
>
inline
void
copy_or_max_alpha(
	Src const &_src,
	Dest &_dest
)
{
	mizuiro::color::conversion::detail::copy_or_default_channel(
		mizuiro::color::conversion::detail::channel_to_max_function<
			Dest
		>(
			_dest
		),
		mizuiro::color::channel::alpha(),
		_src,
		_dest
	);
}

}
}
}
}

#endif
