//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_COLOR_POINTER_RAW_HPP_INCLUDED
#define MIZUIRO_ACCESS_COLOR_POINTER_RAW_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_impl.hpp>
#include <mizuiro/image/format_store.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/size_type.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Constness,
	typename Ptr,
	size_type Stride
>
typename color::types::pointer<
	Access,
	typename Format::color_format,
	Constness
>::type
color_pointer(
	Access const &,
	mizuiro::image::format_store<
		Format
	> const &,
	Constness const &,
	mizuiro::image::detail::stride_pointer<
		Ptr,
		Stride
	> const pointer
)
{
	return pointer.get();
}

}
}

#endif
