//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TO_COLOR_FORMAT_STORE_HPP_INCLUDED
#define MIZUIRO_IMAGE_TO_COLOR_FORMAT_STORE_HPP_INCLUDED

#include <mizuiro/color/format_store_impl.hpp>
#include <mizuiro/detail/null_ptr.hpp>
#include <mizuiro/image/format_store_impl.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename ImageFormat
>
mizuiro::color::format_store<
	typename ImageFormat::color_format
> const
to_color_format_store(
	mizuiro::image::format_store<
		ImageFormat
	> const &_format
)
{
	// Currently, interleaved formats have state if their color
	// formats have state. This code could be simplified if this
	// will be always the case.
	return
		_format.get()
		?
			_format.get()->format_store()
		:
			typename ImageFormat::format_store_type(
				mizuiro::detail::null_ptr()
			)
		;
}

}
}

#endif
