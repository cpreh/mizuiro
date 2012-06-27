//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/detail/format_argument.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/format_is_static.hpp>
#include <mizuiro/image/format_store_impl.hpp>


namespace mizuiro
{
namespace image
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename ImageFormat
>
struct format_argument
:
mizuiro::detail::format_argument<
	ImageFormat,
	mizuiro::image::format_is_static<
		ImageFormat
	>,
	mizuiro::image::format_store<
		ImageFormat
	>
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
