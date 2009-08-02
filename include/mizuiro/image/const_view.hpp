#ifndef MIZUIRO_IMAGE_CONST_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_CONST_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_fwd.hpp>
#include <mizuiro/detail/const_tag.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename T
>
struct const_view;

template<
	typename Format,
	typename Constness
>
struct const_view<
	view<
		Format,
		Constness
	>
>
{
	typedef view<
		Format,
		mizuiro::detail::const_tag
	> type;
};

}
}

#endif
