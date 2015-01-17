//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_INCREMENT_DIM_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_INCREMENT_DIM_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_impl.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	mizuiro::size_type Size
>
inline
mizuiro::image::dimension<
	Size
>
increment_dim(
	mizuiro::image::dimension<
		Size
	> const _size,
	mizuiro::image::dimension<
		Size
	> _current
)
{
	++_current[
		0
	];

	for(
		mizuiro::size_type i = 0u;
		i < Size - 1u;
		++i
	)
		if(
			_current[i]
			==
			_size[i]
		)
		{
			_current[i] = 0;

			++_current[i + 1];
		}

	return
		_current;
}

}
}
}

#endif
