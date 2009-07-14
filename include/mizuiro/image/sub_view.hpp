#ifndef MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View,
	typename Bound
>
View const
sub_view(
	View const &view,
	Bound const &bound
)
{
#if 0
	return View(
		view.dim(),
		view.data(),
		view.data()
		+ detail::subview_offset(
			view.pitch(),
			bound
		),
		detail::subview_pitch(
			view.pitch(),
			bound
		)
	);
#endif
}

}
}

#endif
