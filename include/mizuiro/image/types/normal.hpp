#ifndef MIZUIRO_IMAGE_TYPES_NORMAL_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_NORMAL_HPP_INCLUDED

#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/pointer.hpp>
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
	::mizuiro::access::normal,
	Format,
	Constness
>
:
mizuiro::color::types::pointer<
	::mizuiro::access::normal,
	typename Format::color_format,
	Constness
>
{};

}
}
}

#endif
