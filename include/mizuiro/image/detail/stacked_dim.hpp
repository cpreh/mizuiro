//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_STACKED_DIM_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_STACKED_DIM_HPP_INCLUDED

#include <mizuiro/image/detail/stacked_dim_type.hpp>
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
typename detail::stacked_dim_type<
	Dim
>::type const
stacked_dim(
	Dim const &dim
)
{
	typedef typename detail::stacked_dim_type<
		Dim
	>::type stacked_type;

	stacked_type ret = {{}};

	typename Dim::value_type cur = 1;

	for(
		typename Dim::size_type i = 0;
		i < ret.size();
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
