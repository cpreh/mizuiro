#ifndef MIZUIRO_IMAGE_ITERATOR_COLOR_DATA_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_COLOR_DATA_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Iterator
>
typename mizuiro::color::types::pointer<
	typename Iterator::access,
	typename Iterator::color_format,
	typename Iterator::constness
>::type
iterator_color_data(
	Iterator const &iterator
)
{
	return
		color_pointer(
			typename Iterator::access(),
			typename Iterator::format(),
			typename Iterator::constness(),
			iterator.data()
		);
}

}
}

#endif
