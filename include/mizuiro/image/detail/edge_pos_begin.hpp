//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_EDGE_POS_BEGIN_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_EDGE_POS_BEGIN_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Bound
>
typename
Bound::dim
edge_pos_begin(
	Bound const &_bound,
	typename Bound::size_type const _index
)
{
	typedef typename Bound::dim dim;

	dim ret;

	for(
		typename dim::size_type i = 0;
		i < dim::static_size;
		++i
	)
		ret[i] =
			(i == _index + 1)
			? _bound.pos()[i] + 1
			: _bound.pos()[i];

	return ret;
}

}
}
}

#endif
