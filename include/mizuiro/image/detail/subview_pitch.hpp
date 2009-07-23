#ifndef MIZURIO_IMAGE_DETAIL_SUBVIEW_PITCH_HPP_INCLUDED
#define MIZURIO_IMAGE_DETAIL_SUBVIEW_PITCH_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename View
>
typename View::pitch_type const
subview_pitch(
	View const &view,
	typename View::bound_type const &bound
)
{
}

}
}
}

#endif
