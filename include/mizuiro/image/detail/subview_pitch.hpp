#ifndef MIZURIO_IMAGE_DETAIL_SUBVIEW_PITCH_HPP_INCLUDED
#define MIZURIO_IMAGE_DETAIL_SUBVIEW_PITCH_HPP_INCLUDED

#include <mizuiro/image/detail/edge_pos_end.hpp>
#include <mizuiro/image/detail/edge_pos_begin.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/bound_impl.hpp>
#include <iterator>

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
	typedef typename View::pitch_type pitch_type;

	pitch_type ret;

	for(
		typename pitch_type::size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
		ret[i] = view.dim()[i] > 1
			? std::distance(
				iterator_position(
					view,
					edge_pos_end(
						bound,
						i
					)
				).data(),
				iterator_position(
					view,
					edge_pos_begin<
						typename View::bound_type
					>(
						i
					)
				).data()
			)
			: 0;

	return ret;
}

}
}
}

#endif
