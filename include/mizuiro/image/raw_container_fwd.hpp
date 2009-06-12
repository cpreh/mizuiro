#ifndef MIZUIRO_IMAGE_RAW_CONTAINER_FWD_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_CONTAINER_FWD_HPP_INCLUDED

#include <memory>

namespace mizuiro
{
namespace image
{

template<
	typename T,
	typename A = std::allocator<T>
>
class raw_container;

}
}

#endif
