#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_TYPE_HPP_INCLUDED

#include <mizuiro/image/dimension_decl.hpp>//fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/difference_type.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename T
>
struct pitch_type;

template<
	mizuiro::size_type Dim
>
struct pitch_type<
	dimension<
		Dim,
		mizuiro::size_type
	>
>
{
	typedef dimension<
		Dim - 1,
		mizuiro::difference_type
	> type;
};

template<
	typename T
>
struct pitch_type<
	dimension<
		0,
		T
	>
>
{};

}
}
}

#endif
