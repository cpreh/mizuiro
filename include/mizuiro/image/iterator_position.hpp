#ifndef MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/pitch_iterator_impl.hpp>

namespace mizuiro
{
namespace image
{

// TODO: make this work with linear_iterator as well!

template<
	typename Format,
	typename Constness
>
typename Format::dim_type const
iterator_position(
	pitch_iterator<
		Format,
		Constness
	> const &it
)
{
}

}
}

#endif
