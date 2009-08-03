#ifndef MIZUIRO_IMAGE_MAKE_CONST_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_MAKE_CONST_VIEW_HPP_INCLUDED

#include <mizuiro/image/const_view.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename const_view<
	View
>::type const
make_const_view(
	View const &v
)
{
	return typename const_view<
		View
	>::type(
		v
	);
}

}
}

#endif
