#ifndef MIZUIRO_IMAGE_TYPES_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_RAW_HPP_INCLUDED

#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/normal.hpp>
#include <mizuiro/image/detail/stride_pointer_impl.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/access/normal.hpp>

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
		types::pointer<
			::mizuiro::access::normal,
			Format,
			Constness
		>,
		Format::color_format::element_count
	> type;	
};

}
}
}

#endif
