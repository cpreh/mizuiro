#ifndef MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_POSITION_HPP_INCLUDED

#include <mizuiro/image/detail/stacked_dim_type.hpp>
#include <mizuiro/image/detail/stacked_dim.hpp>
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

	typedef typename detail::stacked_dim_type<
		dim_type
	>::type stacked_dim_type;
	
	stacked_dim_type const stacked_dims(
		detail::stacked_dim(
			it.dim()
		)
	);

	typedef typename dim_type::size_type size_type;

	dim_type d;

	for (
		size_type i = 0;
		i < dim_type::static_size;
		++i
	)
	{
		d[i] = it.offset();

		for (
			size_type m = dim_type::static_size - 1;
			m > i;
			--m
		)
			d[i] %= stacked_dims[i];

		if(i > 0)
			d[i] /= stacked_dims[i - 1];
	}
	
	return d;
}

}
}

#endif
