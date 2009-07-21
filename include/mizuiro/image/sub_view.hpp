#ifndef MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/detail/subview_offset.hpp>
//#include <mizuiro/image/detail/subview_pitch.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
View const
sub_view(
	View const &view,
	typename View::bound_type const &bound
)
{
#if 0
	return View(
		view.outer_dim(),
		bound.dimensions(),
		view.data(),
		detail::subview_offset(
			view.data(),
			view.pitch(),
			view.dim(),
			bound
		),
		detail::subview_pitch(
			view.pitch(),
			view.dim(),
			bound
		)
	);
#endif
}

}
}

#endif
