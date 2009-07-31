#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_POSITION_DENOMINATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_POSITION_DENOMINATOR_HPP_INCLUDED

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
iterator_position_denominator(
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
	return 
		iterator_position_dim_size
		(
			it,
			static_cast
			<
				typename pitch_iterator
				<
					Format,
					Constness
				>::dim_type::size_type
			>
			(
				i-1
			)
		);

}

}
}
}

#endif
