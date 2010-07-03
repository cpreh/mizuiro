//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_MOVE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_MOVE_ITERATOR_HPP_INCLUDED

namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename View::iterator
move_iterator(
	View const &view,
	typename View::dim_type const &pos
)
{
	typename View::iterator ret(
		view.begin()
	);

	typedef typename View::dim_type dim_type;

	dim_type const dim(
		view.dim()
	);

	typename View::iterator::difference_type
		add = 0,
		multiplier = 1;

	for(
		typename dim_type::size_type i = 0;
		i < dim_type::static_size;
		++i
	)
	{
		add += pos[i] * multiplier;

		multiplier *= dim[i];
	}

	ret += add;
	
	return ret;
}

}
}

#endif
