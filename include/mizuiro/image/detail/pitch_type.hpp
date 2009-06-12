#ifndef MIZUIRO_IMAGE_DETAIL_PITCH_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_PITCH_TYPE_HPP_INCLUDED

#include <mizuiro/image/dimension_decl.hpp>//fwd.hpp>
#include <mizuiro/size_type.hpp>

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
		Dim
	>
>
{
	typedef dimension<
		Dim - 1
	> type;
};

template<>
struct pitch_type<
	dimension<0>
>
{};

}
}
}

#endif
