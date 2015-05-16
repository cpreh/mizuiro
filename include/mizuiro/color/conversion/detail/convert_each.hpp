//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_CONVERT_EACH_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_CONVERT_EACH_HPP_INCLUDED

#include <mizuiro/no_init.hpp>
#include <mizuiro/color/for_some_channels.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/channel/alpha.hpp>
#include <mizuiro/color/channel/undefined.hpp>
#include <mizuiro/color/conversion/detail/copy_or_max_alpha.hpp>
#include <mizuiro/color/conversion/detail/copy_or_min_channel_function.hpp>
#include <mizuiro/color/conversion/detail/exclude_channel_function.hpp>
#include <mizuiro/color/conversion/detail/make_logical_and.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Dest,
	typename Src,
	typename Converter
>
inline
mizuiro::color::object<
	Dest
> const
convert_each(
	Src const &_src,
	Converter const &_converter,
	typename
	mizuiro::color::object<
		Dest
	>::format_store_type const &_format
)
{
	typedef
	mizuiro::color::object<
		Dest
	>
	dest_type;

	dest_type dest(
		mizuiro::no_init{},
		_format
	);

	mizuiro::color::for_some_channels(
		_src,
		mizuiro::color::conversion::detail::copy_or_min_channel_function<
			Converter,
			Src,
			dest_type
		>(
			_converter,
			_src,
			dest
		),
		mizuiro::color::conversion::detail::make_logical_and(
			mizuiro::color::conversion::detail::exclude_channel_function<
				typename
				Src::format,
				mizuiro::color::channel::alpha
			>(
				_src.format_store()
			),
			mizuiro::color::conversion::detail::exclude_channel_function<
				typename
				Src::format,
				mizuiro::color::channel::undefined
			>(
				_src.format_store()
			)
		)
	);

	mizuiro::color::conversion::detail::copy_or_max_alpha(
		_src,
		dest
	);

	return
		dest;
}

}
}
}
}

#endif
