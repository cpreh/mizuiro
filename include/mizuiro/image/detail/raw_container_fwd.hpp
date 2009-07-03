#ifndef MIZUIRO_IMAGE_DETAIL_RAW_CONTAINER_FWD_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RAW_CONTAINER_FWD_HPP_INCLUDED

#include <memory>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename T,
	typename A = std::allocator<T>
>
class raw_container;

}
}
}

#endif
