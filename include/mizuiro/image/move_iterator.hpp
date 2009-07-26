#ifndef MIZUIRO_IMAGE_MOVE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_MOVE_ITERATOR_HPP_INCLUDED

#include <numeric>
#include <functional>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename View::iterator
move_iterator(
	View const &view,
	typename View::dim_type const &pos
)
{
	typename View::iterator ret(
		view.begin()
	);

	typedef typename View::dim_type dim_type;

	dim_type const dim(
		view.dim()
	);

	for(
		typename dim_type::size_type i = 0;
		i < dim_type::static_size;
		++i
	)
		ret += 
			pos[i] *
			std::accumulate(
				dim.begin(),
				dim.begin() + i,
				1,
				std::multiplies<
					typename dim_type::size_type
				>()
			);
	
	return ret;
}

}
}

#endif
