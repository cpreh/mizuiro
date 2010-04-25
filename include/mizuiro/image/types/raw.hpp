#ifndef MIZUIRO_IMAGE_TYPES_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_RAW_HPP_INCLUDED

#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/detail/stride_pointer_impl.hpp>
#include <mizuiro/color/types/homogenous_raw.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/access/raw.hpp>

namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename Format,
	typename Constness
>
struct pointer<
	::mizuiro::access::raw,
	Format,
	Constness
>
{
	typedef detail::stride_pointer<
		typename color::types::pointer<
			::mizuiro::access::raw,
			typename Format::color_format,
			Constness
		>::type,
		sizeof(typename Format::color_format::channel_type)
	> type;	
};

}
}
}

#endif
