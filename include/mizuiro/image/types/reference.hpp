#ifndef MIZUIRO_IMAGE_TYPES_REFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_REFERENCE_HPP_INCLUDED

#include <mizuiro/color/proxy_fwd.hpp>

namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename Access,
	typename Format,
	typename Constness
>
struct reference
{
	typedef ::mizuiro::color::proxy<
		Access,
		Format,
		Constness
	> type;
};

}
}
}

#endif
