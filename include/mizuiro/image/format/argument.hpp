//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/detail/format_argument.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/format/store_impl.hpp>
#include <mizuiro/image/types/needs_store.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename ImageFormat
>
struct argument
:
mizuiro::detail::format_argument<
	ImageFormat,
	mizuiro::image::types::needs_store<
		ImageFormat
	>,
	mizuiro::image::format::store<
		ImageFormat
	>
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}
}

#endif
