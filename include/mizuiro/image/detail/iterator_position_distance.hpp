#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_POSITION_DISTANCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_POSITION_DISTANCE_HPP_INCLUDED

#include <boost/type_traits/make_signed.hpp>
#include <numeric>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Dim
>
typename boost::make_signed<
	typename Dim::size_type
>::type
iterator_position_distance(
	Dim const &dim_,
	Dim const &pos,
	Dim const &otherpos
)
{
	typedef typename boost::make_signed<
		typename Dim::size_type
	>::type difference_type;

	difference_type ret = 0;

	for(
		size_type i = 0;
		i < Dim::static_size;
		++i
	)
		ret +=
			(
				static_cast<
					difference_type
				>(
					otherpos[i]
				)
				- static_cast<
					difference_type
				>(
					pos[i]
				)
			)
			* static_cast<
			 	difference_type
			>(
			 	std::accumulate(
					dim_.begin(),
					dim_.begin() + i,
					1,
					std::multiplies<
						size_type
					>()
				)
			);

	return ret;
}

}
}
}

#endif
