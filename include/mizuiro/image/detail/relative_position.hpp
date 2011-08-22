//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_RELATIVE_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RELATIVE_POSITION_HPP_INCLUDED

#include <mizuiro/image/detail/stacked_dim_type.hpp>
#include <mizuiro/image/detail/stacked_dim.hpp>
#include <mizuiro/image/dimension_impl.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	mizuiro::size_type Dim,
	typename DimValue,
	typename Offset
>
image::dimension<
	Dim,
	DimValue
> const
relative_position(
	image::dimension<
		Dim,
		DimValue
	> const &_dim,
	Offset const _offset
)
{
	typedef image::dimension<
		Dim,
		DimValue
	> dim_type;

	typedef typename detail::stacked_dim_type<
		dim_type
	>::type stacked_dim_type;

	stacked_dim_type const stacked_dims(
		detail::stacked_dim<
			typename dim_type::value_type
		>(
			_dim
		)
	);

	typedef typename dim_type::size_type size_type;

	dim_type ret;

	for (
		size_type i = 0;
		i < dim_type::static_size;
		++i
	)
	{
		ret[i] =
			static_cast<
				typename dim_type::value_type
			>(
				_offset
			);

		for (
			size_type m = dim_type::static_size - 1;
			m > i;
			--m
		)
			ret[i] %= stacked_dims[i];

		if(i > 0)
			ret[i] /= stacked_dims[i - 1];
	}

	return ret;
}

}
}
}

#endif
