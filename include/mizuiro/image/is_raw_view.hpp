#ifndef MIZUIRO_IMAGE_IS_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_IS_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/detail/is_raw_access.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
struct is_raw_view
:
detail::is_raw_access<
	typename View::color_format::access_types
>
{};

}
}

#endif
