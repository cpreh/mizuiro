#ifndef MIZUIRO_IMAGE_ACCESS_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_RAW_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_impl.hpp>
#include <mizuiro/image/access/color_pointer.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/size_type.hpp>

namespace mizuiro
{
namespace image
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
	detail::stride_pointer<
		Ptr,
		Stride
	> const pointer
)
{
	return pointer.get();
}

}
}
}

#endif
