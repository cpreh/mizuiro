#ifndef MIZURIO_IMAGE_DETAIL_SUB_VIEW_OFFSET_HPP_INCLUDED
#define MIZURIO_IMAGE_DETAIL_SUB_VIEW_OFFSET_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename View,
	typename Constness
>
typename View::dim_type::value_type
subview_offset(
	typename View::pitch_type const &pitch,
	typename View::dim_type const &dim,
	typename View::bound_type const &bound
)
{
/*
	return pitch_iterator<
		Format,
		Constness
	>(
		dim,
		data,
		begin,
		pitch
	);
*/
}

}
}
}

#endif
