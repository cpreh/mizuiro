#ifndef MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/bound_impl.hpp>
#include <mizuiro/image/iterator_position.hpp>
#include <mizuiro/image/detail/subview_pitch.hpp>

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
	return View(
		bound.dimensions(),
		view.data(),
		iterator_position(
			view,
			bound.positions()
		).data(),
		view.root_pitch(),
		detail::subview_pitch(
			view,
			bound
		)
	);
}

}
}

#endif
