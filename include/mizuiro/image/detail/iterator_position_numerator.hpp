#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_POSITION_NUMERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_POSITION_NUMERATOR_HPP_INCLUDED

#include <mizuiro/image/detail/iterator_position_dim_size.hpp>
#include <mizuiro/image/pitch_iterator_impl.hpp>
#include <mizuiro/image/dimension_impl.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Format,
	typename Constness
>
typename pitch_iterator<
		Format,
		Constness
	>::dim_type::size_type const
iterator_position_numerator(
	pitch_iterator<
		Format,
		Constness
	> const &it,
	typename pitch_iterator<
		Format,
		Constness
	>::dim_type::size_type const i
)
{
	typedef typename 
		pitch_iterator<
			Format,
			Constness
		>::dim_type dim_type;
	typedef typename 
		dim_type::size_type size_type;
	
	return i
		== static_cast<
			size_type
		>(
			dim_type::static_size - 1
		)
		?
			it.data() - it.root_data()
		:
			iterator_position_numerator(
				it,
				static_cast<
					size_type
				>(
					i + 1
				)
			) 
			% 
			iterator_position_dim_size
			(
				it,
				i
			);
}

}
}
}

#endif
