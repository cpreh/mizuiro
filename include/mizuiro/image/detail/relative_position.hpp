//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_RELATIVE_POSITION_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_RELATIVE_POSITION_HPP_INCLUDED

#include <mizuiro/no_init.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/detail/stacked_dim.hpp>
#include <mizuiro/image/detail/stacked_dim_array.hpp>


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
mizuiro::image::dimension<
	Dim,
	DimValue
>
relative_position(
	mizuiro::image::dimension<
		Dim,
		DimValue
	> const &_dim,
	Offset const _offset
)
{
	using
	dim
	=
	mizuiro::image::dimension<
		Dim,
		DimValue
	>;

	using
	stacked_dim_array
	=
	mizuiro::image::detail::stacked_dim_array<
		dim
	>;

	stacked_dim_array const stacked_dims(
		mizuiro::image::detail::stacked_dim<
			typename dim::value_type
		>(
			_dim
		)
	);

	using
	size_type
	=
	typename
	dim::size_type;

	dim ret{
		mizuiro::no_init{}
	};

	for(
		size_type i = 0;
		i < dim::static_size;
		++i
	)
	{
		ret[i] =
			static_cast<
				typename dim::value_type
			>(
				_offset
			);

		for (
			size_type m = dim::static_size - 1;
			m > i;
			--m
		)
		{
			ret[i] %= stacked_dims[i];
		}

		if(i > 0)
		{
			ret[i] /= stacked_dims[i - 1];
		}
	}

	return ret;
}

}
}
}

#endif
