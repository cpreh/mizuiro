#ifndef MIZUIRO_IMAGE_STORE_FWD_HPP_INCLUDED
#define MIZUIRO_IMAGE_STORE_FWD_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Access
		= ::mizuiro::access::normal
>
class store;

}
}

#endif
