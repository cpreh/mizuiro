#ifndef MIZUIRO_ACCESS_COLOR_POINTER_RAW_HPP_INCLUDED
#define MIZUIRO_ACCESS_COLOR_POINTER_RAW_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_impl.hpp>
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
	Format const &,
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
