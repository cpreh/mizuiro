#ifndef MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/bound_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
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
		move_iterator(
			view,
			bound.positions()
		).data(),
		detail::subview_pitch(
			view,
			bound
		)
	);
}

}
}

#endif
