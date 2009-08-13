#ifndef MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/detail/iterator_position_numerator.hpp>
#include <mizuiro/image/detail/iterator_position_denominator.hpp>
#include <mizuiro/image/dimension_impl.hpp>
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
	typedef typename pitch_iterator<
		Format,
		Constness
	>::dim_type dim_type;

	dim_type d;

	for (
		typename dim_type::size_type i = 0;
		i < dim_type::static_size;
		++i
	)
		d[i] =
			detail::iterator_position_numerator(it,i)
			/ detail::iterator_position_denominator(it,i);
	
	return d;
}

}
}

#endif
