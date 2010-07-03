//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_STACKED_DIM_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_STACKED_DIM_HPP_INCLUDED

#include <mizuiro/image/detail/stacked_dim_type.hpp>
#include <mizuiro/image/detail/pitch_type.hpp>
#include <mizuiro/image/dimension_impl.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Dim
>
typename stacked_dim_type<
	Dim
>::type const
stacked_dim(
	Dim const &dim
)
{
	typename stacked_dim_type<
		Dim
	>::type ret;

	typedef typename Dim::size_type size_type;

	typedef typename pitch_type<
		Dim
	>::type pitch_type;

	size_type cur = 1;

	for(
		size_type i = 0;
		i < pitch_type::static_size;
		++i
	)
	{
		cur *= dim[i];
		ret[i] = cur;
	}

	return ret;
}

}
}
}

#endif
