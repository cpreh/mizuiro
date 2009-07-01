#ifndef MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_SUB_VIEW_HPP_INCLUDED

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename View,
	typename Bound
>
view<
	iterator<
		Format,
		typename View::constness
	>
> const
sub_view(
	View const &view,
	Bound const &bound
)
{
	return view<
		iterator<
			Format,
			typename View::constness
		>
	>(
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
}

}
}

#endif
