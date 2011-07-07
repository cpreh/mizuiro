//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_SAME_TO_SAME_HPP_INCLUDED

#include <mizuiro/color/conversion/detail/copy_and_convert_channel_functor.hpp>
#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/conversion/detail/exclude_channel_functor.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/for_some_channels.hpp>
#include <mizuiro/color/object_impl.hpp>

namespace mizuiro
{
namespace color
{
namespace conversion
{

template<
	typename Dest,
	typename Src
>
color::object<
	Dest
> const
same_to_same(
	Src const &_src,
	typename color::object<
		Dest
	>::format_store_type const &_format
		= color::format_argument<Dest>::get()
)
{
	typedef color::object<
		Dest
	> dest_type;

	dest_type dest(
		_format
	);

	mizuiro::color::for_some_channels(
		_src,
		detail::copy_and_convert_channel_functor<
			Src,
			dest_type,
			float
		>(
			_src,
			dest
		),
		detail::exclude_channel_functor<
			typename Src::format,
			channel::alpha
		>(
			_src.format_store()
		)
	);
		
	detail::copy_or_max_alpha(
		_src,
		dest
	);

	return dest;
}

}
}
}

#endif
